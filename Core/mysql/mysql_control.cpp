//DBINFO.h
#pragma once

struct DBINFO
{
    const char* ip;
    const char* user;
    const char* pwd;
    const char* db_name;
    unsigned int port;
};

//DBconnect.h
#pragma once

#include "DBINFO.h"
#include <mysql.h>
#include <iostream>

class DBconnect
{
public:
    DBconnect();
    ~DBconnect();
    
    MYSQL* getConnectDB();
    void RealConnectDB(DBINFO info);
    void Query(std::string qry);
    void ShowSelectQuery();
    MYSQL_RES* getResult();
    MYSQL_ROW getRow();
    int getField();

    void Destroy();


private:
    MYSQL_RES* res;
    MYSQL_ROW row;
    int field;
    MYSQL* conn;
};


//DBconnect.cpp
#include "DBconnect.h"
#include <string>


DBconnect::DBconnect() : 
    field(0)
{
    conn = mysql_init(NULL);
    if (conn == NULL)
    {
        std::cout << "mysql_init() failed" << std::endl;
    }
}

DBconnect::~DBconnect()
{
    if(conn != NULL)
    {
        mysql_close(conn);
    }
    if (res != NULL)
    {
        mysql_free_result(res);
    }

}

MYSQL* DBconnect::getConnectDB()
{
    return conn;
}

void DBconnect::RealConnectDB(DBINFO info)
{
    if (mysql_real_connect(
        conn,
        info.ip,
        info.user,
        info.pwd,
        info.db_name,
        info.port,
        NULL,
        0) == NULL)
    {
        std::cout << mysql_error(conn);
        mysql_close(conn);
        exit(1);
    }
    if (mysql_query(conn, "set names euckr"))
    {
        std::cout << mysql_error(conn) << std::endl;
        mysql_close(conn);
    }
}

void DBconnect::Query(std::string qry)
{
    std::string query = qry.substr(0, 6);

    if (mysql_query(conn, qry.c_str()))
    {
        std::cout << mysql_error(conn) << std::endl;
        mysql_close(conn);
    }
    res = mysql_store_result(conn);

    if (query == "select" || query == "SELECT")
    {
        //std::cout << "query == select || query == SELECT" << std::endl;
        ShowSelectQuery();
    }

}

void DBconnect::ShowSelectQuery()
{
    MYSQL_ROW _row;
    while ((_row = getRow()) != NULL)
    {
        for (int i = 0; i < getField(); i++)
        {
            std::cout << (_row[i] ? _row[i] : NULL) << "\t";
        }
        std::cout << std::endl;
    }

}


MYSQL_RES* DBconnect::getResult()
{
    return res;
}

MYSQL_ROW DBconnect::getRow()
{
    row = mysql_fetch_row(res);
    return row;
}

int DBconnect::getField()
{
    field = mysql_num_fields(res);
    return field;
}

void DBconnect::Destroy()
{
    if (conn != NULL)
    {
        mysql_close(conn);
    }
    if (res != NULL)
    {
        mysql_free_result(res);
    }
}


// main.cpp
#include "DBINFO.h"
#include "DBconnect.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    DBINFO db_info = {
        "localhost",
        "root",
        "ai123",
        "sqldb",
        0
    };

    DBconnect db;
    db.RealConnectDB(db_info);
    db.Query("use testdb");

    int select = -1;
    do
    {
        cout << "---------------------------------------------------------------- -" << endl;
        cout << "1. 주소록 조회" << endl;
        cout << "2. 주소록 추가" << endl;
        cout << "3. 주소록 수정" << endl;
        cout << "4. 주소록 삭제" << endl;
        cout << "5. 종료" << endl;
        cout << " 메뉴 : ";
        cin >> select;
        system("cls");

        switch (select)
        {
        case 1:
       cout << "ADDR_ID\t NAME\t HP\t" << endl;
            db.Query("SELECT * FROM address_book");
            cout << endl << endl;
            break;
        case 2:
        {
            string _name, _hp;
            cout << "이름을 입력해주세요. : ";
            cin >> _name;
            cout << "전화번호를 입력해주세요. : ";
            cin >> _hp;

            db.Query("INSERT INTO address_book(name, hp) VALUES('" + _name + "', '" + _hp + "')");
            break;
        }
        case 3:
        {
            string id, name, hp;
            cout << "ID를 입력해주세요. : ";
            cin >> id;
            cout << "이름을 입력해주세요. : ";
            cin >> name;
            cout << "전화번호를 입력해주세요. : ";
            cin >> hp;
            db.Query("UPDATE address_book SET name = '" + name + "', hp = '" + hp + "' WHERE addr_id = "+ id +"");
            break;
        }
        case 4:
        {
            string id;
            cout << "ID를 입력해주세요. : ";
            cin >> id;
            db.Query("DELETE FROM address_book WHERE addr_id = " + id + "");
            break;
        }
        case 5:
            select = 0;
            break;
        default:
            break;
        }
    } while (select != 0);
    
    db.Destroy();
}
 
