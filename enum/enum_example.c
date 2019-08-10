#include <stdio.h>

int main( void )
{
     enum opcodes { open, close, lock, unlock };
     int instruction, size = 4;

     printf( "Instruction? >> " );
     fflush( stdout );
     if ( scanf( "%d", &instruction ) != 1 )
     {
          fprintf( stderr, "Invalid instruction.\n" );
          return 1;
     }
     if ( instruction < 0 || instruction >= size )
     {
          fprintf( stderr, "Invalid instruction.\n" );
          return 1;
     }
     switch( instruction )
     {
          case open   : printf( "Open selected.\n" );
                        break;
          case close  : printf( "Close selected.\n" );
                        break;
          case lock   : printf( "Lock selected.\n" );
                        break;
          case unlock : printf( "Unlock selected.\n" );
                        break;
          default     : printf( "Error, invalid opcode.\n" );
                        return 1;
     }
     return 0;
}

/* EOF */
