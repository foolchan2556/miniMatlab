#############################################################################
# Makefile for building: ../../examples/bin/plotter
# Generated by qmake (2.01a) (Qt 4.6.2) on: ?? 12? 25 17:26:04 2010
# Project:  plotter.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile plotter.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_SVG_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtSvg -I/usr/include/qt4 -I/usr/include/qwt-qt4 -Imoc -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -L../../lib -lqwt-qt4 -lQtSvg -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = obj/

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		plotter.cpp \
		item.cpp \
		workspace.cpp \
		ftable.cpp \
		comm.cpp \
		cmdengine.cpp moc/moc_mainwindow.cpp \
		moc/moc_plotter.cpp
OBJECTS       = obj/main.o \
		obj/mainwindow.o \
		obj/plotter.o \
		obj/item.o \
		obj/workspace.o \
		obj/ftable.o \
		obj/comm.o \
		obj/cmdengine.o \
		obj/moc_mainwindow.o \
		obj/moc_plotter.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		plotter.pro
QMAKE_TARGET  = plotter
DESTDIR       = ../../examples/bin/
TARGET        = ../../examples/bin/plotter

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_plotter.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) ../../examples/bin/ || $(MKDIR) ../../examples/bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: plotter.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtSvg.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile plotter.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtSvg.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile plotter.pro

dist: 
	@$(CHK_DIR_EXISTS) obj/plotter1.0.0 || $(MKDIR) obj/plotter1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) obj/plotter1.0.0/ && $(COPY_FILE) --parents mainwindow.h plotter.h workspace.h matrix.h item.h ftable.h comm.h cmdengine.h obj/plotter1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp plotter.cpp item.cpp workspace.cpp ftable.cpp comm.cpp cmdengine.cpp obj/plotter1.0.0/ && $(COPY_FILE) --parents mainwindow.ui plotter.ui obj/plotter1.0.0/ && (cd `dirname obj/plotter1.0.0` && $(TAR) plotter1.0.0.tar plotter1.0.0 && $(COMPRESS) plotter1.0.0.tar) && $(MOVE) `dirname obj/plotter1.0.0`/plotter1.0.0.tar.gz . && $(DEL_FILE) -r obj/plotter1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc/moc_mainwindow.cpp moc/moc_plotter.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc/moc_mainwindow.cpp moc/moc_plotter.cpp
moc/moc_mainwindow.cpp: cmdengine.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc/moc_mainwindow.cpp

moc/moc_plotter.cpp: /usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		plotter.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) plotter.h -o moc/moc_plotter.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_plotter.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_plotter.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_plotter.h: plotter.ui \
		/usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h
	/usr/bin/uic-qt4 plotter.ui -o ui_plotter.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

obj/main.o: main.cpp mainwindow.h \
		cmdengine.h \
		plotter.h \
		/usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/main.o main.cpp

obj/mainwindow.o: mainwindow.cpp mainwindow.h \
		cmdengine.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/mainwindow.o mainwindow.cpp

obj/plotter.o: plotter.cpp /usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_scale_engine.h \
		/usr/include/qwt-qt4/qwt_scale_div.h \
		/usr/include/qwt-qt4/qwt_valuelist.h \
		/usr/include/qwt-qt4/qwt_double_interval.h \
		/usr/include/qwt-qt4/qwt_symbol.h \
		/usr/include/qwt-qt4/qwt_plot_grid.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_marker.h \
		/usr/include/qwt-qt4/qwt_plot_curve.h \
		/usr/include/qwt-qt4/qwt_polygon.h \
		/usr/include/qwt-qt4/qwt_data.h \
		/usr/include/qwt-qt4/qwt_legend.h \
		plotter.h \
		/usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h \
		ui_plotter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/plotter.o plotter.cpp

obj/item.o: item.cpp item.h \
		ftable.h \
		matrix.h \
		comm.h \
		workspace.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/item.o item.cpp

obj/workspace.o: workspace.cpp workspace.h \
		item.h \
		ftable.h \
		matrix.h \
		comm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/workspace.o workspace.cpp

obj/ftable.o: ftable.cpp ftable.h \
		matrix.h \
		comm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/ftable.o ftable.cpp

obj/comm.o: comm.cpp comm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/comm.o comm.cpp

obj/cmdengine.o: cmdengine.cpp cmdengine.h \
		item.h \
		ftable.h \
		matrix.h \
		comm.h \
		workspace.h \
		plotter.h \
		/usr/include/qwt-qt4/qwt_plot.h \
		/usr/include/qwt-qt4/qwt_global.h \
		/usr/include/qwt-qt4/qwt_array.h \
		/usr/include/qwt-qt4/qwt_text.h \
		/usr/include/qwt-qt4/qwt_plot_dict.h \
		/usr/include/qwt-qt4/qwt_plot_item.h \
		/usr/include/qwt-qt4/qwt_legend_itemmanager.h \
		/usr/include/qwt-qt4/qwt_double_rect.h \
		/usr/include/qwt-qt4/qwt_scale_map.h \
		/usr/include/qwt-qt4/qwt_math.h \
		/usr/include/qwt-qt4/qwt_plot_printfilter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/cmdengine.o cmdengine.cpp

obj/moc_mainwindow.o: moc/moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_mainwindow.o moc/moc_mainwindow.cpp

obj/moc_plotter.o: moc/moc_plotter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_plotter.o moc/moc_plotter.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
