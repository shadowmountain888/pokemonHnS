SeafoamIslands_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	setflag FLAG_TEMP_1
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	msgbox SeafoamIslands_Gym_Text_BlaineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLAINE, SeafoamIslands_Gym_Text_BlaineWinLoss
	message SeafoamIslands_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SeafoamIslands_Gym_Text_TM, MSGBOX_DEFAULT
	giveitem ITEM_TM_OVERHEAT
	setflag FLAG_BADGE15_GET
	setflag FLAG_DEFEATED_CINNABAR_ISLAND_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 15
	clearflag FLAG_HIDE_SEAFOAM_GYMGUY
	call Common_EventScript_SetGymTrainers
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Blaine_Defeated::
	msgbox SeafoamIslands_Gym_Text_BlaineAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafomIslands2_EventScript_GymGuide::
	goto_if_set FLAG_TEMP_2, SeafomIslands2_EventScript_GymGuide2
	msgbox SeafoamIslands_Gym_Text_GymGuideWin, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end
SeafomIslands2_EventScript_GymGuide2::
	msgbox SeafoamIslands_Gym_Text_GymGuideWin2, MSGBOX_NPC
	end

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE15_GET, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SeafoamIslands_Gym_Text_GymStatue::
    .string "{JPN}グレンタウン ポケモンジム\n"
	.string "{JPN}ジムリーダー: カツラ\p"
	.string "{JPN}\n"
	.string "{JPN}しょうりした トレーナー:\nグリーン レッド$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
    .string "{JPN}グレンタウン ポケモンジム\n"
	.string "{JPN}ジムリーダー: カツラ\p"
    .string "{JPN}\n"
	.string "{JPN}しょうりした トレーナー:\nグリーン レッド {PLAYER}$"

SeafoamIslands_Gym_Text_TM:
	.string "{JPN}これも もっていけ.この\n"
	.string "{JPN}わざマシンには すごい\l"
	.string "{JPN}オーバーヒートが はいってるぞ.\p"
	.string "{JPN}\nつぎの あいては やけどなおしを\nよういしておいたほうが いいな!\lワーハハハ!$"
SeafoamIslands_Gym_Text_BlaineIntro:
	.string "{JPN}カツラ: ワーハハハ!\p"
	.string "{JPN}\n"
	.string "{JPN}グレンタウンの わしの ジムは\n"
	.string "{JPN}やけてしまったのじゃ.\p"
	.string "{JPN}\n"
	.string "{JPN}かざんの せいで ほのおを はく\n"
	.string "{JPN}ポケモンたちと わしは\l"
	.string "{JPN}いえを うしなってしまった.\p"
	.string "{JPN}\n"
	.string "{JPN}ワーハハハ!\p\nしかし わしは この どうくつで\nジムリーダーとして ふっかつじゃ!\p\nわしに かてたら バッジを\nやろうぞ.\p\nハハ! やけどなおしを\nよういしておくんじゃな!$"

SeafoamIslands_Gym_Text_BlaineWinLoss:
	.string "{JPN}カツラ: すばらしい.わしは\n"
	.string "{JPN}もえつきてしまったわい...\pきみは ボルケノバッジを\nかちとった!$"

SeafoamIslands_Gym_Text_ReceivedVolcanoBadge:
	.string "{JPN}{PLAYER}は ボルケーノバッジを\nてにいれた!$"

SeafoamIslands_Gym_Text_BlaineAfterBattle:
	.string "{JPN}カツラ: こんかいは まけたが\n"
	.string "{JPN}つぎは かつぞ.\p"
	.string "{JPN}\n"
	.string "{JPN}グレンタウンの ジムを さいけん\nしたら また しょうぶじゃ!$"

SeafoamIslands_Gym_Text_BlaineFightDone:
	.string "{JPN}カツラ: わしの ほのおポケモンは\n"
	.string "{JPN}もっと つよくなるぞ.\p"
	.string "{JPN}\nみておれ!$"

SeafoamIslands_Gym_Text_BlaineRematch:
	.string "{JPN}カツラ: おお!\p"
	.string "{JPN}\n"
	.string "{JPN}きみは カントーちゃんぴおんに\n"
	.string "{JPN}なったのじゃな!\p"
	.string "{JPN}\n"
	.string "{JPN}もえあがるぞ!\p"
	.string "{JPN}\nきみの うでまえは いちりゅうじゃ.\p\nわしは いつでも しょうぶ\nたいきじゃ.\p\nわしと もういちど しょうぶ\nするかね?$"

SeafoamIslands_Gym_Text_BlaineRematchDefeat:
	.string "{JPN}カツラ: きみの うでまえは\n"
	.string "{JPN}ほんとうに ほのおのようじゃ!\p"
	.string "{JPN}\nわしの ぼうぎょを やききって\nしまったぞ!$"

SeafoamIslands_Gym_Text_GymGuideWin:
	.string "{JPN}よお!\p"
	.string "{JPN}...あれ? もうおわったのか?\p"
	.string "{JPN}ごめん ごめん!\p"
	.string "{JPN}グレンジムが なくなって\n"
	.string "{JPN}しまったから きみを みつけ\l"
	.string "{JPN}られなかったんだ.\p"
	.string "{JPN}でも きみは わたしの アドバイス\nなしでも じゅうぶん つよいな.\lかつと おもってたよ!$"

SeafoamIslands_Gym_Text_GymGuideWin2:
	.string "{JPN}ポケモンジムは ジムリーダーが\n"
	.string "{JPN}いれば どこでも なりたつのじゃ.\p"
	.string "{JPN}\nたてものは ひつようないぞ.$"
