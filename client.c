#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void main(){
  int cs;
  char buf[5];
  struct sockaddr_in csa;                                 // 주소설정 구조체
  
  memset(&csa, 0, sizeof(csa));
  csa.sin_family = AF_INET;                               // 인터넷 소켓
  csa.sin_addr.s_addr = inet_addr(127.0.0.1);             // 127.0.0.1 = 루프백 주소
  csa.sin_port = htons(11234);                            // 포트번호 11234
  
  cs = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  connect(cs, (struct sockaddr *) &csa, sizeof(csa));
  
  recv(cs, buf, 5, 0);                                    // 5바이트 문자를 받아서 출력
  printf("Receive [%s]\n", buf);
  
  close(cs);
}
