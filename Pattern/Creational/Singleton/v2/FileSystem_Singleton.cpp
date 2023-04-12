#include <iostream>
#include <string>
#include <mutex>

class FileSystem {
 public:
  static FileSystem& GetInstance() {
    static FileSystem instance;
    return instance;
  }

  void ReadFile(const std::string& filename) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << "Reading file " << filename << std::endl;
  }

  void WriteFile(const std::string& filename) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << "Writing file " << filename << std::endl;
  }

 private:
  FileSystem() {}

  FileSystem(const FileSystem&) = delete;
  FileSystem& operator=(const FileSystem&) = delete;

  std::mutex mutex_;
};

int main() {
  FileSystem& fs1 = FileSystem::GetInstance();
  FileSystem& fs2 = FileSystem::GetInstance();

  fs1.ReadFile("test.txt");
  fs2.WriteFile("output.txt");

  return 0;
}
