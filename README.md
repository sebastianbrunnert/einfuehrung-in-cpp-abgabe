Grundsätzlich wurden keine weiteren Anforderungen an die Entwicklungsumgebung gestellt. Daher kann das Programm genau wie vorgegeben kompiliert und ausgeführt werden:

1. Ins Terminal navigieren, z. B. in der Konsole mit `cd cpp-sommersemester-2025/Abgabe_Vorlage`
2. Nur beim ersten Mal: Die Befehle `make getSFML` und `make getGTest` ausführen, um Ressourcen herunterzuladen.
3. Das Projekt und die Tests bauen: `make game` bzw. `make tests`
4. Den Pfad im Terminal anpassen: `export LD_LIBRARY_PATH=./SFML/lib:$LD_LIBRARY_PATH`
5. Das Spiel oder die Test ausführen (in der Konsolen-Anwendung, nicht VSCode!): `./game` oder `./tests`

Ablauf des Spiels:

1. Der Spieler startet das Spiel. Die Aliens (technisch zusammengefasst in einem Alien-Block) erscheinen auf dem Bildschirm und beginnen sich zu bewegen.
2. Der Spieler kann mit den Pfeiltasten das Raumschiff nach links und rechts bewegen, um den Schüssen der Aliens auszuweichen. Diejenigen Aliens, die im Block keine Aliens unter sich haben schießen ab und zu. Je weiter fortgeschritten das Spiel ist, desto schneller bewegen sich die Aliens und desto mehr Schüsse feuern sie ab.
3. Der Spieler kann mit der Leertaste schießen, um die Aliens zu treffen. Ein getroffenes Alien gibt Punkte. Sind alle Aliens im Block getroffen, wird der Block zurückgesetzt, die Geschwindigkeit erhöht und die Schusswahrscheinlichkeit der Aliens steigt.
4. Wird der Spieler getroffen, verliert er ein Leben. Sind alle Leben verloren, ist das Spiel vorbei. Das Spiel zeigt dann eine "Game Over"-Nachricht an.
5. Das Spiel ist auch vorbei, wenn die ersten Aliens den unteren Bildschirmrand erreichen.
6. Erweiterung: Eine weitere Schwierigkeit ist die bewegende Barriere. Kugeln, die die Barriere treffen, prallen ab und ändern ihre Richtung.