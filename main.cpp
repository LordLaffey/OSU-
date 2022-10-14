/**
 *  __    __     _____     __         ______  
 * /\ "-./  \   /\  __-.  /\ \       /\  == \ 
 * \ \ \-./\ \  \ \ \/\ \ \ \ \____  \ \  _-/ 
 *  \ \_\ \ \_\  \ \____-  \ \_____\  \ \_\   
 *   \/_/  \/_/   \/____/   \/_____/   \/_/   
 * 
 * @version v0.06
*/

#include "header.cpp"
#include "md_player.cpp"
#include "fourkey_player.cpp"
#include "settings.cpp"
#include "recorder.cpp"
using namespace std;

void PlayMain();

int main()
{   
    ClearScreen();
    setting.load();
    Music.MusicPrework();
    while(true)
    {
        ClearScreen();
        cout << "===============================MDLP Main Menu=============================" << endl;
        cout << "1. Play(p)" << endl;
        cout << "2. Record(r)" << endl;
        cout << "3. Music(m)" <<endl;
        cout << "4. Settings(s)" << endl;
        cout << "5. Quit(q)" << endl;
        cout << "==========================================================================" << endl;
        
        char c = WaitForInput();
        switch(c)
        {
            case 'p': case 'P': PlayMain(); break;
            case 'r': case 'R': RecordMain(); break;
            case 'm': case 'M': Music.MusicMain(); break;
            case 's': case 'S': SettingsMain(); break;
            case 'q': case 'Q': goto end;
        }
    }
    
    end:
    
    ClearScreen();
    Print("Thanks for playing MDLP  >w<", 20);
}

void PlayMain(){

    ClearScreen();

    cout << "Choose a mode:" << endl;
    cout << "1. MuseDash Mode" << endl;
    cout << "2. 4K Mode" << endl;
    cout << "3. Back" << endl;

    while(1)
    {
        if(!_kbhit()) continue;
        char c=_getch();
        switch(c){
            case '1': MDPlayerMain();return ;
            case '2': FourKeyPlayerMain();return ;
            case '3': return ;
        }
    }

}
