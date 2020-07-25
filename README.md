# RainRoad
### @AUTHOR: 
##### Trevor Knott
``` chmod +x ./zrv.sh ```
./zrv.sh main
./zrv.sh <#OfExample>
./zrv.sh main >> output.txt     _to see terminal output in file for grep debugging_

* 2dGraphics
 -> churchWindows
 -> comp00t
* 2dGames
 -> sp8crs
* 3dGraphics
 -> repulsionism
* 3dGames
* EleLand


### GlLand
```
  ...     ...
 7/20/20 gLit_Mesh
 7/25/20 gLit_GUI
```

##### TmaKe by TK, aka meh
```
# How I run my servers.

  #!/bin/bash
  _FREETYPE="
    -I/usr/include/freetype2
    -I/usr/include/libpng16
    -I/usr/include/harfbuzz
    -I/usr/include/glib-2.0
    -I/usr/lib/glib-2.0/include"

  _IGNORE="
  -Wno-unused-function 
  -Wno-unused-variable"

  _LINKERS="
    -lglfw -lGLEW -DGLEW_STATIC -lGL
    -lfreetype"

  _O="./runtime/main"

  source ../utils.sh

  function clean() {
    if test -f "main.o"; then
      rm -rf *.o
    fi
   }


 clean
 echo "    - COMPILING BINARY"
	#  - Compiling styles -
	# Style 1) w/ -o only    :  (real 0m11.803s|user 0m10.881s|sys 0m0.891s)
	# Style 2) w/ .o linkers :  (real 0m15.355s|user 0m14.233s|sys 0m1.080s)
	# 1) g++ -Wall src/$1.cpp src/ctrls/*.cpp $_FREETYPE $_IGNORE -o ./runtime/$1 $_LINKERS 
	g++ -Wall -c src/$1.cpp src/ctrls/*.cpp $_FREETYPE $_IGNORE  && g++ *.o $_LINKERS -o $_O   

	echo "    - RUNNING BINARY"
	clean && $_O

```
