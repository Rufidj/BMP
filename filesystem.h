global
string fichero;
string mp3ext="*.mp3";
string mp4ext="*.mp4";
string imageext[3]="*.png","*.map";



function explora();
begin
loop
fichero=glob(&mp4ext);
say(""+fichero);
frame;
end
end
