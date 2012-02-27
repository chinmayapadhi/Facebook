rm -fr SWATFacebook *.o Makefile debug/ release/; export PATH=/opt/qt4-maemo5/bin/:$PATH;qmake SWATFacebook.pro; make clean; make
mv SWATFacebook sfb
scp sfb portaali.org:/var/www/html/iao.fi/
