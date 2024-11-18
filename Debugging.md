gdb listeninmain.cpp
break 49
break 52
break 64
run
info locals (Alle Speicheradressen)
print element1->inhalt ("Erstes Element")
print element2->inhalt ("Zweites Element")
..
cont
list 50
print outputTempElement (=erstesElement)
print erstesElement
cont
print outputTempElement (=zweitesElement)
print zweitesElement
...
cont
list 64
info locals //lösche Elemente
cont
info locals