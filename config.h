global
int langfile; //idenficador fichero de idioma
int filecfg; // idenficador fichero configuracion
string config="config.cfg"; //nombre configuracion
string archivos;

int ancho=1290;   // ancho pantalla
int alto=720;    // alto pantalla
int prof=32;    // profundudidad de color

string videopath="video/"; //directorio de los videos
string musicpath="music/"; //directorio de la musica
string imagepath="images/"; //directorio de las imagenes

string videofile="everest.avi"; //Archivo video por defecto
string musicfile="audio.mp3"; // Archivo de musica por defecto
string imagefile=""; // Archivo de imagen por defecto

//---------------------------------------------------
// STRINGS PARA EL IDIOMA
//---------------------------------------------------
string txt1;
string txt2;
string txt3;
string txt4;
string txt5;
string txt6;
string txt7;
string txt8;
int tx1;
int tx2;


//--------------------------------------------------------
// FUNCION QUE CONFIGURA CARPETAS Y ARCHIVOS
//--------------------------------------------------------

function configure();
begin
      if(file_exists(config)); //comprueba si existe fichero de configuracion
      say("Cargando..: "+config);
      load_config();
      say("Cargado!");
      else
      say("Creando archivo de configuracion.."); // en caso contrario crea uno nuevo..
      // escribe la configuracion //
      filecfg=fopen(config,o_write);
      fputs(filecfg,ancho);
      fputs(filecfg,alto);
      fputs(filecfg,prof);
      fputs(filecfg,videopath);
      fputs(filecfg,musicpath);
      fputs(filecfg,imagepath);
      fputs(filecfg,"**FIN DE ARCHIVO DE CONFIGURACION**");
      fclose(filecfg);
      say("Archivo "+config+" creado con exito");
      //***************//
      // Creamos los directorios //
      mkdir(videopath);
      mkdir(musicpath);
      mkdir(imagepath);

    end
end

//------------------------------------------------------
// FUNCION QUE CARGA CONFIGURACION
//------------------------------------------------------

function load_config();
begin
     filecfg=fopen(config,o_read);
     ancho=fgets(filecfg);
     alto=fgets(filecfg);
     prof=fgets(filecfg);
     videopath=fgets(filecfg);
     musicpath=fgets(filecfg);
     imagepath=fgets(filecfg);
     fclose(filecfg);
end


function menu_config();
begin
     langfile=fopen("data/lang/es/es.txt",o_read);
     txt1=fgets(langfile);
     txt2=fgets(langfile);
     txt3=fgets(langfile);
     txt4=fgets(langfile);
     txt5=fgets(langfile);
     txt6=fgets(langfile);
     txt7=fgets(langfile);
     txt8=fgets(langfile);
     write(0,10,10,14,"Utilice las teclas de direccion para cambiar de seccion");
     write(0,10,30,14,"Despues pulse enter,para entrar en dicha opcion,y escriba ");
     tx1=write_string(0,555,200,14,&txt1);
     tx2=write_string(0,555,250,14,&txt2);
     loop
         if(key(_right));
		 move_text(tx2,300,250,14);
		 write_string(0,555,250,14,&txt3);
		 end
     frame;
   end
end











