ViridianCity_Gym_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Blue::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_BLUE, ViridianCity_Gym_EventScript_BlueAtDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_BlueGotoDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_Blue_Defeated
	msgbox ViridianCity_Gym_Text_LeaderBlue_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE, ViridianCity_Gym_Text_LeaderBlue_Win
	message ViridianCity_Gym_Text_ReceivedEarthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ViridianCity_Gym_Text_LeaderBlue_After, MSGBOX_DEFAULT
	giveitem ITEM_TM_BULK_UP
	setflag FLAG_BADGE16_GET
	setflag FLAG_DEFEATED_VIRIDIAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers
	closemessage
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_HIDE_CERULEANCAVE_GUARD
	setflag FLAG_HIDE_SEAFOAM_BLAINE
	clearflag FLAG_HIDE_CINNABAR_BLAINE
	release
	end

ViridianCity_Gym_EventScript_Blue_Defeated::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_BlueGotoDojo::
	msgbox ViridianCity_Gym_Text_BlueGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_BLUE
	release
	end

ViridianCity_Gym_Text_BlueGotoDojo:
	.string "{JPN}ブルー: もう もどってきたのか?\p"
	.string "{JPN}おれに もういちど いどみたい\n"
	.string "{JPN}なら かくとうどうじょうに こい!$"

ViridianCity_Gym_EventScript_BlueAtDojo::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "{JPN}グリーン: よお! やっと きたな!\p"
	.string "{JPN}グレンじまでは きぶんじゃ\n"
	.string "{JPN}なかったけど いまなら\n"
	.string "{JPN}バトルする きになったぜ.\p"
	.string "{JPN}...\p"
	.string "{JPN}まさか ジョウトの ジムを\n"
	.string "{JPN}ぜんぶ せいはしたって\n"
	.string "{JPN}いうのか?\p"
	.string "{JPN}へっ! ジョウトの ジムなんて\n"
	.string "{JPN}たいしたことないんだな.\p"
	.string "{JPN}まあ しんぱいすんなよ.\p"
	.string "{JPN}いま バトルすれば おまえが\nつよいかどうか すぐに\nわかるからな.\nじゅんびは いいか\nジョウトチャンプ?$"

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "{JPN}なんてこった！\p"
	.string "{JPN}オレがこんなヤツに\n"
	.string "{JPN}まけちまうなんてっ！！\p"
	.string "...\n"
	.string "{JPN}..ちっしょうがねえ\l"
	.string "{JPN}ほらグリーンバッジだ\l"
	.string "{JPN}おまえにやるよ！$"
ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{JPN}{PLAYER}は アースバッジを\nてにいれた!$"

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "...\p"
	.string "{JPN}オレがまちがってたよ\n"
	.string "{JPN}おまえはほんものだよ\l"
	.string "{JPN}つよいトレーナーだ！\l"
	.string "{JPN}すなおにみとめるぜ！\p"
	.string "{JPN}だがな！\n"
	.string "{JPN}わすれるな！\p"
	.string "{JPN}いつかオレがおまえを\n"
	.string "{JPN}たおすからなっ！$"
ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "{JPN}ブルー: いいか おまえ\p"
	.string "{JPN}おれが おまえを たおすまで\n"
	.string "{JPN}まけるんじゃないぞ わかったか?$"


ViridianCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_GymGuyAfter
	msgbox ViridianCity_Gym_Text_Guide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymGuyAfter::
	msgbox ViridianCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end

ViridianCity_Gym_Text_Guide:
	.string "{JPN}よお みらいの チャンピオン!\p"
	.string "{JPN}ちょうしは どうだ? いいかんじで\n"
	.string "{JPN}すすんでるじゃないか\p"
	.string "{JPN}ジムリーダーは 3ねんまえに\n"
	.string "{JPN}チャンピオンと たたかった やつだ\p"
	.string "{JPN}なかなか つよいぞ\n"
	.string "{JPN}ぜんりょくで がんばれよ!$"

ViridianCity_Gym_Text_Guide_Win:
	.string "{JPN}さすがつよいねっ！\p"
	.string "{JPN}あまりにもかんどうてきな\n"
	.string "{JPN}しょうぶをみせてもらって\l"
	.string "{JPN}オレっちなみだがでちゃったよ！$"

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
    .string "{JPN}トキワ ポケモンジム\n"
	.string "{JPN}リーダー: ブルー\p"
	.string "{JPN}しょうりしゃ:\n"
	.string "{JPN}ブルー レッド$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "{JPN}トキワ ポケモンジム\n"
	.string "{JPN}リーダー: ブルー\p"
    .string "{JPN}しょうりしゃ:\n"
	.string "{JPN}ブルー レッド {PLAYER}$"

