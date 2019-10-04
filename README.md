# smsrun
Sailfish dbus listener for incoming sms and command trigger

SMSRUN listens on the dbus service org.ofono.MessageManager from sim card slot 1(/ril_0). 
It is an example application for Sailfish
which listens on incoming sms messages and triggers a command.
You can define a phone number whitelist in /home/nemo/.config/smsrun/whitelist.txt so only these numbers
are allowd to execute a command. Further you need to have key word and a command. Therefore you find
a file in /home/nemo/.config/smsrun/cmdlist.txt where you can write your key word (the sms message text),
which is seperated by a tabulator from the followed command which you like to run.

Maybe it would be better to do it with telepathy but I don't know how.


