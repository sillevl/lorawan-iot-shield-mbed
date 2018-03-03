#include "mbed.h"

// Serial pc(USBTX, USBRX, 115200);
Serial rn2483(D1, D0, 57600);
DigitalOut rn2483Reset(A0);
DigitalOut rn2483Reset_d2(D2);

//DigitalOut led1(LED1);

void waitForResponse() {
  while (!rn2483.readable() ) {
  }
  while (true){
    if(rn2483.readable()){
      char c = rn2483.getc();
      if(c == '\n'){
        // pc.printf("\r\n");
        break;
      } else {
        // pc.putc(c);
      }
    }
  }
}

void sendCmd( char *cmd) {
  // pc.printf( cmd );
  // pc.printf("\r\n");
  rn2483.printf(cmd);
  rn2483.printf("\r\n");
  waitForResponse();
}

char getHexHi( char ch ) {
  char nibble = ch >> 4;
  return (nibble > 9) ? nibble + 'A' - 10 : nibble + '0';
}
char getHexLo( char ch ) {
  char nibble = ch & 0x0f;
  return (nibble > 9) ? nibble + 'A' - 10 : nibble + '0';
}

void sendData( char *data) {
  // pc.printf( "mac tx uncnf 1 " );
  rn2483.printf( "mac tx uncnf 1 " );
  // // Write data as hex characters
  // char *ptr = data;
  // int idiotCount = 50;
  // while (*ptr && idiotCount ) {
  //   rn2483.printf( getHexHi( *ptr ) );
  //   rn2483.printf( getHexLo( *ptr ) );
  //
  //   pc.printf( getHexHi( *ptr ) );
  //   pc.printf( getHexLo( *ptr ) );
  //
  //   ptr++;
  //   idiotCount--;
  // }
  // pc.printf( data );
  rn2483.printf(data);

  rn2483.printf("\r\n");
  // pc.printf("\r\n");

  waitForResponse();
  wait_ms(5000);
    // Serial.write(lora.read());
}

int main()
{
//   led1 = 1;
  // pc.baud(115200);
  rn2483.baud(57600);
  
  // pc.printf("\r\n *** RN2483 Test ***\r\n");
  wait_ms(500);
  rn2483Reset = 1;
  rn2483Reset_d2 = 1;
  wait_ms(500);
  rn2483Reset = 0;
  rn2483Reset_d2 = 0;
  wait_ms(500);
  rn2483Reset = 1;
  rn2483Reset_d2 = 1;
  wait_ms(500);

  sendCmd("sys factoryRESET");
  sendCmd("sys get hweui");
  sendCmd("mac get deveui");

  // For TTN
  sendCmd("mac set devaddr 26011FA4");  // Set own address
  sendCmd("mac set appskey 2BE21D61B7E3FE4A5AFB770B467D78DF");
  sendCmd("mac set nwkskey EDB901DEA2071CD923306E2B29DCBF2B");
  sendCmd("mac set adr off");
  sendCmd("mac set rx2 3 869525000");
  sendCmd("mac join abp");
  sendCmd("mac get status");
  sendCmd("mac get devaddr");

  while(true){
    sendData("AB");
    wait_ms(5000);
  }
}
