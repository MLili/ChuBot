# Variablen
Version = libircclient-1.6

# Alle Befehle ausführen
alle: loeschen installation

# Loeschen
loeschen:
	rm $(Version).tar.gz
	rm -r $(Version)

# Laedt runter und installiert
installation:
	wget http://sourceforge.net/projects/libircclient/files/libircclient/1.6/libircclient-1.6.tar.gz
	tar -zxf $(Version).tar.gz
	cd $(Version); ./configure; make; cd -
	cd bot; make; cd -
