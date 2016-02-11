include "modules.h"
include "config.h"
include "filesystem.h"
global
	
process main();
begin
SET_FPS(100,0);
configure();
set_mode(ancho,alto,prof);
reproduce();
//explora();
//menu_config();
loop
if(key(_Esc));exit("",1);end
		frame;
		end
	end
	
process reproduce();
begin
graph=video_play(videopath+videofile,ancho,alto);
x=320;
y=240;
say("reproduciendo : "+videopath+videofile);
loop
if(mouse.left)size++;end
if(mouse.right)size--;end
if(key(_left))x=x-5;end
if(key(_right))x=x+5;end
if(key(_up))y=y-5;end
if(key(_down))y=y+5;end
if(key(_alt)and(key(_enter)));set_mode(ancho,alto,prof,mode_fullscreen);end
frame;
end
end
