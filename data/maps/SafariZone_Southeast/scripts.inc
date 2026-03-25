.set LOCALID_MANTYKEMAN, 7

SafariZone_Southeast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	.byte 0

SafariZone_Southeast_GliscorEvo::
	msgbox SafariZone_Southeast_GliscorEvo_Text, MSGBOX_NPC
	end

SafariZone_Southeast_GliscorEvo_Text:
	.string "{JPN}わたし シンオウちほうの\n"
	.string "{JPN}ポケモンが だいすきなの!\p"
	.string "{JPN}グライガーを つかまえて\n"
	.string "{JPN}グライオンに しなくちゃ!\p"
	.string "{JPN}よるにしか しんかしないのよ\nニューラや ヤミカラスと\nおなじようにね!$"

SafariZone_Southeast_MantykeEvo::
	msgbox SafariZone_Southeast_MantykeEvo_Text, MSGBOX_SIGN
	waitmessage
	msgbox SafariZone_Southeast_MantykeEvo_Text2, MSGBOX_NPC
	applymovement LOCALID_MANTYKEMAN, SafariZone_Southeast_MantykeEvoMoves
	waitmovement 0
	end

SafariZone_Southeast_MantykeEvoMoves:
	face_right
	step_end

SafariZone_Southeast_MantykeEvo_Text:
	.string "{JPN}あっ!$"

SafariZone_Southeast_MantykeEvo_Text2:
	.string "{JPN}みた? いまの!\p"
	.string "{JPN}あの マンタインが しんかしようと\n"
	.string "{JPN}して みずのはどうを つかってた!\l"
	.string "{JPN}しぜんって うつくしいのね!$"

@ Event scripts for SafariZone_Southeast are in SafariZone_South/scripts.inc
