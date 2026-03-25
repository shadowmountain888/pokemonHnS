VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_NEST_BALL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_NONE
	release
	end

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "{JPN}ポケモンのしあいでは\n"
	.string "{JPN}Xスペシャルがじゅうようだ.\p"
	.string "{JPN}いちかいのたたかいだけだが\n"
	.string "{JPN}いくつかのわざのいりょくを\nあげてくれるんだ.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "{JPN}バトルテントで かつための\n"
	.string "{JPN}こうりゃくほんは うってない\n"
	.string "{JPN}みたいだね...\p"
	.string "{JPN}やっぱり じぶんの ちからで\nがんばるしか ないのかな...$"
VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "{JPN}ネストボールはよわったポケモンに\n"
	.string "{JPN}よくきくんだ.\p"
	.string "{JPN}シダケタウンでしかかえない\n"
	.string "{JPN}ちんしひんだよ.$"

