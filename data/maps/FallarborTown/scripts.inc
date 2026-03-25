FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_ECRUTEAK_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "{JPN}なにかが おこっているよ!\n"
	.string "{JPN}きに いらないね!\p"
	.string "{JPN}あやしい やつらが\n"
	.string "{JPN}コズモはかせの いえを\lうろうろ しているのを\nみたんだ...$"
FallarborTown_Text_RegionKnownForMeteors:
	.string "{JPN}このちほうは むかしから\n"
	.string "{JPN}いんせきで ゆうめいなんだよ.\p"
	.string "{JPN}りゅうせいのたきは むかし\n"
	.string "{JPN}おちてきた いんせきで\lできたと いわれているよ.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "{JPN}みてよ! みてよ!\n"
	.string "{JPN}だいじな アズリルだよ!\p"
	.string "{JPN}つるつる すべすべで\nふわふわなんだ!$"

FallarborTown_Text_Azurill:
	.string "{JPN}アズリル: るりるりー.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "{JPN}もう アスナと たたかったかい?\n"
	.string "{JPN}フエンジムの リーダーだよ.\p"
	.string "{JPN}あのこの おじいさんは ゆうめいで\n"
	.string "{JPN}むかし ポケモンリーグの してんのう\l"
	.string "{JPN}だったんだ.\p"
	.string "{JPN}アスナも いつか すごい\n"
	.string "{JPN}トレーナーに なるかも しれないね.$"
	.string ""

FallarborTown_Text_BattleTentSign:
	.string "{JPN}バトルテント ハジツゲしてん\n"
	.string "{JPN}さいきょうチーム しゅうけつ!$"

FallarborTown_Text_TownSign:
	.string "{JPN}ハジツゲタウン\n"
	.string "{JPN}ちいさな はたけの のうそんちいき$"

FallarborTown_Text_MoveTutorSign:
	.string "{JPN}わざおしえの いえ\n"
	.string "{JPN}ポケモンに あたらしいわざを おしえます$"

