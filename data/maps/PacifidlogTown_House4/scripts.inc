PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "{JPN}みんなが いってたよ\n"
	.string "{JPN}ホウエンの うえのほうで\l"
	.string "{JPN}ポケモンが とんでるって\p"
	.string "{JPN}いつも とびまわってるのかな?\nどこかで やすまなくても\lへいきなのかなあ?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "{JPN}そらの ポケモン!\n"
	.string "{JPN}そらの ポケモン!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "{JPN}きみ どこから きたの?$"

PacifidlogTown_House4_Text_YesTown:
	.string "{JPN}そう?\n"
	.string "{JPN}ソウタウン?\p"
	.string "{JPN}そんな ばしょ\nきいたことないなあ$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "{JPN}ちがう? それって へんだよ\n"
	.string "{JPN}どこかから きたはずでしょ\p"
	.string "{JPN}ああ! まって!\n"
	.string "{JPN}まさか うみのそこで\lうまれたとか いわないよね?$"

