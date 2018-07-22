#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

char* rmSpace(char *stg){
    int counter=0;
    char* newchar = new char[32];

    for(int i = 0; i<strlen(stg);i++){
        if(stg[i]!= ' '){
            while(stg[i]!=' ') {
                newchar[counter]=stg[i];
                counter++;
                i++;
            }
              break;
        }
    }
    return newchar;
    delete[] newchar;
}

int main()
{
    char output[BUFSIZ];
    char list[50][BUFSIZ];
    int i=0;
    FILE *fp = popen("nmcli device wifi","r");
    while ( fgets( output, BUFSIZ, fp ) != NULL ) {
        printf("%i %s",i,output);
        char* newStr = new char[32];
        newStr = rmSpace(output);
        for(int j = 0;j <strlen(newStr); j++){
                list[i][j]=newStr[j];
            }
        delete[] newStr;
        i++;
    }
    pclose (fp);
    int num;
    char pass[64];
    std::cout << "choose network\n";
    std::cin >> num;
    //130 cose wpa maxpass ~= 63
    char request[130] = "nmcli device wifi connect ";
    strcat (request,list[num]);
     std::cout << request;
    strcat (request, " password ");
    std::cout << "\nenter password ";
    std::cin >> pass;
    strcat (request,pass);
    system(request);
    return 0;
}

