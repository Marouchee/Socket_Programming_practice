#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void main(){
  int ss, sa;
  struct sockaddr_in ssa;                           // 주소설정 구조체
  
  memset(&ssa, 0, sizeof(ssa));
  ssa.sin_family = AF_INET;                         // 인터넷 소켓
  ssa.sin_addr.s_aadr = htonl(INADDR_ANY);
  ssa.sin_port = htons(11234);                      // 포트번호 11234
    
  ss = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  bind(ss, (struct sockaddt *) &ssa, sizeof(ssa));  // 바인딩
  
  while(True){                                      // 무한루프 - 데몬
    listen(ss, 10);
    sa = accept(ss, 0, 0);
    send(sa, 'test', 5, 0);                         // 5바이트 'test' 전송
    close(sa);
  }
}
