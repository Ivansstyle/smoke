TEMPLATE = app
CONFIG += console
CONFIG += debug


TARGET = smoke
SOURCES += src/main.cpp \
    src/particlesystem.cpp \
    src/particle.cpp \
    src/controlsphere.cpp
HEADERS += \
    src/particlesystem.h \
    src/particle.h \
    src/controlsphere.h



# Multiplatform : Linux

unix:linux{
  INCLUDEPATH += . /usr/include packages/obj-0.1
  LIBS += -lSDL2 -lglut -lGLU -lGL -lpng
  OBJECTS_DIR = obj
  DEFINES += __OS_LINUX__
          }





# Multiplatform : Mac OsX
macx{
  DEFINES += __OS_OSX__
  LIBS += -F/Library/Frameworks -framework SDL2
  LIBS += -F/Library/Frameworks -framework SDL2_image
  INCLUDEPATH  += Library/Frameworks/SDL.framework/Headers
  INCLUDEPATH  += /usr/local/include
  INCLUDEPATH  += /usr/local/include/SDL2
  INCLUDEPATH  += /Library/Frameworks/SDL2_image.framework/Headers
  QMAKE_LFLAGS += -F/Library/Frameworks

  LIBS += -framework OpenGL
    }

QMAKE_CFLAGS += -std=c++11

