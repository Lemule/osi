#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t childPid;
    int status;

    if ((childPid = fork()) == 0) {
        exit(0);
    }
    else if (childPid == -1) {
        std::cerr << "������ ��� �������� ��������� ��������" << std::endl;
        return 1;
    }
    else {
        if (waitpid(childPid, &status, 0) == -1) {
            std::cerr << "������ ��� �������� ���������� ��������� ��������" << std::endl;
            return 1;
        }

        if (WIFEXITED(status)) {
            std::cout << "�������� ������� ���������� � �����: " << WEXITSTATUS(status) << std::endl;
        }
        else if (WIFSIGNALED(status)) {
            std::cout << "�������� ������� ��� �������� � ��������: " << WTERMSIG(status) << std::endl;
        }
  
    return 0;
}
