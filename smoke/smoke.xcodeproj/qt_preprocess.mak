#############################################################################
# Makefile for building: smoke.app/Contents/MacOS/smoke
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  smoke.pro
# Template: app
# Command: /Users/ivansstyle/Qt/5.5/ios/bin/qmake -spec macx-ios-clang CONFIG+=iphonesimulator -spec macx-xcode -o smoke.xcodeproj/project.pbxproj smoke.pro
#############################################################################

MAKEFILE      = project.pbxproj

MOC       = /Users/ivansstyle/Qt/5.5/ios/bin/moc
UIC       = 
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DDARWIN_NO_CARBON -DQT_NO_PRINTER -DQT_NO_PRINTDIALOG -DQT_GUI_LIB -DQT_CORE_LIB
INCPATH       = -I. -I/Users/ivansstyle/Qt/5.5/ios/mkspecs/macx-ios-clang/ios -I../../../Qt/5.5/ios/include -I../../../Qt/5.5/ios/include/QtGui -I../../../Qt/5.5/ios/include/QtCore -I. -I../../../Qt/5.5/ios/mkspecs/macx-ios-clang
DEL_FILE  = rm -f
MOVE      = mv -f

preprocess: compilers
clean preprocess_clean: compiler_clean

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compilers:
compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 
