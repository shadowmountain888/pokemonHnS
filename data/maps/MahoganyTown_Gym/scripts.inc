MahoganyTown_Gym_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "{JPN}{PLAYER}はヤナギから\n"
	.string "{JPN}アイスバッジをもらった！$"
MahoganyTown_Gym_Text_GymStatueCertified:
	.string "{JPN}それをもっておると\n"
	.string "{JPN}あれくるううずのうえをすすめる\l"
	.string "{JPN}うずしおなるわざがつかえる\p"
	.string "{JPN}それからこいつは\n"
	.string "{JPN}わたしからのせんべつだよ$"

MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANYTOWN
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
	
MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
	.string "{JPN}ヤナギ: ポケモンもひとも\nいきているといろいろある\p"
	.string "{JPN}わたしもいろいろ\nつらいことをあじわった\p"
	.string "{JPN}じんせいのせんぱいとして\nそれをおしえてやろう\p"
	.string "{JPN}きみがうまれるまえから\nポケモンといっしょにいる\l"
	.string "{JPN}おいそれとまけたりはせん\p"
	.string "{JPN}ふゆのヤナギとよばれる\nそのじつりょくみせてやろうかの\p$"
MahoganyTown_Gym_Text_PryceImpressed:
	.string "{JPN}ヤナギ: うんうん\nみごとなたたかいっぷり\p"
	.string "{JPN}そのつよいきもちがあれば\nなにがあっても\lのりこえていけるだろうよ\p"
	.string "{JPN}うむ!\nこのバッジをもっていきなさい\p$"

MahoganyTown_Gym_Text_ReceivedBadge:
	.string "{JPN}{PLAYER}はヤナギから\nアイスバッジをもらった!$"

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
	.string "{JPN}ヤナギ: それをもっておると\nあれくるううずのうえをすすめる\l"
	.string "{JPN}うずしおなるわざがつかえる\p"
	.string "{JPN}それからこいつは\nわたしからのせんべつだよ\p$"
MahoganyTown_Gym_Text_HailSpeech:
	.string "{JPN}ヤナギ: そいつはあられ\p"
	.string "{JPN}しばらくのあいだあられをふらせ\nこおりタイプいがいのポケモンは\l"
	.string "{JPN}つらいおもいをするであろう!\p"
	.string "{JPN}まさにふゆのきびしさを\nかんじさせるわざよ$"
MahoganyTown_Gym_Text_CherishPokemon:
	.string "{JPN}ヤナギ: こおりとゆきがとければ\nはるになる...\p"
	.string "{JPN}きみはこれからながいじかん\nポケモンといっしょにいられる\l"
	.string "{JPN}それをたいせつにな$"

MahoganyTown_Gym_Text_PryceRematch:
	.string "{JPN}おお ジョウトチャンピオン！\pきみのうでまえは\nまことにすばらしい\pかんしんしたよ\pしかしまだまだ\nまなびあうことがおおい\pわたし ヤナギ\nふゆのトレーナーにも\pまだまだひとあじある\pもういちど しょうぶ\nしてくれるかね？$"
MahoganyTown_Gym_Text_PryceRematchDefeat:
    .string "{JPN}ああ またしても きみの\n"
	.string "{JPN}つよさに かんしんしたよ.\p"
    .string "{JPN}その つよい いしで\n"
	.string "{JPN}じんせいの しょうがいを\nのりこえていけるだろう.$"

MahoganyTown_Gym_Text_Guide:
	.string "{JPN}ヤナギは50ねんも\nポケモンをそだててきたベテラン\pどんなポケモンをだしても\nたいおうできるつよい\lメンバーをもっている\pほのおタイプがこうかてきだが\nあめにはちゅういしろ！$"
MahoganyTown_Gym_Text_GuideWin:
    .string "{JPN}うんうん\n"
	.string "{JPN}みごとなたたかいっぷり\p"
	.string "{JPN}そのつよいきもちがあれば\n"
	.string "{JPN}なにがあっても\l"
	.string "{JPN}のりこえていけるだろうよ\p"
	.string "{JPN}うむ！\n"
	.string "{JPN}このバッジをもっていきなさい$"
MahoganyTown_Gym_Text_BoarderRonaldSeen:
	.string "{JPN}きみのポケモンを\nこおらせてうごけなくしてやる！$"
MahoganyTown_Gym_Text_BoarderRonaldBeaten:
	.string "{JPN}くそ なにもできなかった$"
MahoganyTown_Gym_Text_BoarderRonaldAfter:
	.string "{JPN}こおりじょうたいでも\nつかえるわざが\lあるとおもうんだ$"
MahoganyTown_Gym_Text_BoarderBradSeen:
	.string "{JPN}このジムはゆかが\nつるつるすべるんだ\pたのしいだろ？\pでもあそんでる\nわけじゃないぞ！$"
MahoganyTown_Gym_Text_BoarderBradBeaten:
	.string "{JPN}ぼくたちのしんけんさが\nわかっただろ？$"
MahoganyTown_Gym_Text_BoarderBradAfter:
	.string "{JPN}このジムはさいこうだ\nポケモンといっしょに\lすべるのがだいすきなんだ！$"
MahoganyTown_Gym_Text_BoarderDouglasSeen:
	.string "{JPN}おれはヤナギの\nひみつをしってるぞ$"
MahoganyTown_Gym_Text_BoarderDouglasBeaten:
	.string "{JPN}よし ヤナギのひみつを\nおしえてやる$"
MahoganyTown_Gym_Text_BoarderDouglasAfter:
	.string "{JPN}ヤナギのちからのひみつは..\pまいにちたきにうたれて\nこころとからだを\lきたえているのさ$"
MahoganyTown_Gym_Text_SkierRoxanneSeen:
	.string "{JPN}ジムリーダーのヤナギの\nところにいくには\nかんがえてすべることよ$"
MahoganyTown_Gym_Text_SkierRoxanneBeaten:
	.string "{JPN}スキーならまけないのに！$"
MahoganyTown_Gym_Text_SkierRoxanneAfter:
	.string "{JPN}せいかくにすべらないと\nこのジムではとおくまで\niけないわよ$"
MahoganyTown_Gym_Text_SkierClarissaSeen:
	.string "{JPN}わたしのパラレルターンを\nみてなさい！$"
MahoganyTown_Gym_Text_SkierClarissaBeaten:
	.string "{JPN}いやー！\nころんじゃったじゃない！$"
MahoganyTown_Gym_Text_SkierClarissaAfter:
	.string "{JPN}スキーのじまんなんて\nしなきゃよかった.$"