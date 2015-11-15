
#include "OctahedronSDLApplication.h"

/*
BSc_Graf_OGL_Kisfeladat1
TĂłth Ăkos
RMUGLK

Feladat:

1. KĂŠszĂ­ts egy alkalmazĂĄst amiben lĂŠtrehozol egy origĂł kĂśzĂŠppontĂş, 
   egysĂŠgnyi ĂŠlhosszĂşsĂĄgĂş oktaĂŠdert ( http://hu.wikipedia.org/wiki/Okta%C3%A9der ). 

2. A lĂŠtrehozott geometria minden hĂĄromszĂśgĂŠnek legyen kĂźlĂśnbĂśzĹ szĂ­ne! (25%)

3. A fent elkĂŠszĂ­tett geometriĂĄt rajzold ki a kĂśvetkezĹ formĂĄciĂłban: a z(x,y)=x^3 - x*y + y^2 felĂźlet, 
  -2<=x,y<=2 feletti rĂŠszĂŠnek nĂŠgy sarokpontjĂĄba ĂŠs kĂśzĂŠppontjĂĄban (tehĂĄt z(-2,-2),z(2,-2),z(2,2),z(-2,2),z(0,0) pontokba) (25%)

4. Az Ă­gy kirajzolt formĂĄciĂłt mozgasd a kĂśvetkezĹ pĂĄlyĂĄn: egy origĂł kĂśzĂŠppontĂş,
   9 sugarĂş gĂśmb felĂźletĂŠn (ne sĂ­kbeli legyen a pĂĄlya!) (25%)

5. A felhasznĂĄlĂł a kĂśvetkezĹkĂŠppen ĂĄllĂ­thassa a szĂ­ntĂŠrbeli tĂśrtĂŠnĂŠseket: a szĂłkĂśz billentyĹą lenyomĂĄsĂĄra 
   kezdjenek el forogni a formĂĄciĂłban rĂŠsztvevĹ geometriĂĄk 
   a sajĂĄt Z tengelyĂźk kĂśrĂźl (tehĂĄt ne az egĂŠsz alakzat, hanem kĂźlĂśn-kĂźlĂśn a geometriĂĄk). 
   Ăjabb szĂłkĂśz billentyĹą esetĂŠn ĂĄlljon meg ez a forgĂĄs. 
   A kamerĂĄt a szĂ­ntĂŠrbe Ăşgy helyezd le, hogy lĂĄthatĂł legyen minden! (25%)
   
2015 ĂĄprilis 1.
*/

int main(int argc, char* argv[]){
	
	OctahedronSDLApplication app(argc, argv);
	
	return app.exec();
}
