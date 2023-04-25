#include <iostream>
#include <string>

// 서브시스템 1: 인증
class Authentication {
public:
    bool login(const std::string& username, const std::string& password) {
        // 로그인 프로세스 구현
        return true;
    }
};

// 서브시스템 2: 결제
class Payment {
public:
    bool processPayment(double amount) {
        // 결제 프로세스 구현
        return true;
    }
};

// 서브시스템 3: 플레이어
class MusicPlayer {
public:
    void play(const std::string& song) {
        std::cout << "Playing: " << song << std::endl;
    }
};

// 퍼사드 클래스: 음악 스트리밍 서비스
class MusicStreamingService {
private:
    Authentication auth;
    Payment payment;
    MusicPlayer player;

public:
    bool loginAndPlay(const std::string& username, const std::string& password, double amount, const std::string& song) {
        if (auth.login(username, password)) {
            if (payment.processPayment(amount)) {
                player.play(song);
                return true;
            }
        }
        return false;
    }
};

int main() {
    MusicStreamingService streamingService;
    if (streamingService.loginAndPlay("user", "password", 9.99, "My Favorite Song")) {
        std::cout << "재생 성공!" << std::endl;
    } else {
        std::cout << "재생 실패!" << std::endl;
    }

    return 0;
}
