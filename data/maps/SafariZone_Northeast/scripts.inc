SafariZone_Northeast_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SafariZone_Northeast_AmbipomEvo::
	msgbox SafariZone_Northeast_AmbipomEvo_Text, MSGBOX_NPC
	end

SafariZone_Northeast_AmbipomEvo_Text:
	.string "{JPN}わたし エテボースが\n"
	.string "{JPN}だいすきなの!\l"
	.string "{JPN}とっても かわいいでしょ!\p"
	.string "{JPN}みんなを わらわせる\n"
	.string "{JPN}わざを つかうと\l"
	.string "{JPN}しんかするのよ!\pしんかしても\nやっぱり かわいいの!$"

@ Event scripts for SafariZone_Northeast are in SafariZone_South/scripts.inc
