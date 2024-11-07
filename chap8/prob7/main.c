#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <grp.h>
#include <sys/types.h>

extern char **environ;  


void print_environment_variable(const char *env_var) {
    char *value = getenv(env_var);
    if (value) {
        printf("%s=%s\n", env_var, value);
    } else {
        printf("No environment variable found for: %s\n", env_var);
    }
}


void print_all_environment_variables() {
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "No option provided. Please use an option.\n");
        return 1;
    }

    
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '\0') {
            switch (argv[i][1]) {
                case 'e': 
                    if (argv[i][2] == '\0') {
                        print_all_environment_variables(); 
                    } else {
                        print_environment_variable(argv[i] + 2); 
                    }
                    break;
                case 'u':
                    {
                        uid_t real_uid = getuid();
                        uid_t effective_uid = geteuid();
                        struct passwd *real_user = getpwuid(real_uid);
                        struct passwd *effective_user = getpwuid(effective_uid);
                        printf("My Realistic User ID: %d (%s)\n", real_uid, real_user ? real_user->pw_name : "Unknown");
                        printf("My Valid User ID: %d (%s)\n", effective_uid, effective_user ? effective_user->pw_name : "Unknown");
                    }
                    break;
                case 'g': 
                    {
                        gid_t real_gid = getgid();
                        gid_t effective_gid = getegid();
                        struct group *real_group = getgrgid(real_gid);
                        struct group *effective_group = getgrgid(effective_gid);
                        printf("My Realistic Group ID: %d (%s)\n", real_gid, real_group ? real_group->gr_name : "Unknown");
                        printf("My Valid Group ID: %d (%s)\n", effective_gid, effective_group ? effective_group->gr_name : "Unknown");
                    }
                    break;
                case 'i': 
                    printf("My Process number: [%d]\n", getpid());
                    break;
                case 'p': 
                    printf("My Parent's Process number: [%d]\n", getppid());
                    break;
                default:
                    fprintf(stderr, "Unknown option: %s\n", argv[i]);
                    break;
            }
        } else {
            fprintf(stderr, "Invalid format for option: %s\n", argv[i]);
        }
    }

    return 0;
}

