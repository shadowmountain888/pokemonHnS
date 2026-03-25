.set LOCALID_OLIVINE_CITY_GYM_NPC1, 3
.set LOCALID_OLIVINE_CITY_GYM_NPC2, 2

OlivineCity_Gym_MapScripts::
	.byte 0

OlivineCity_Gym_EventScript_Gent::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Gent2
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Gent2::
	msgbox OlivineCity_Gym_Text_Gent2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_TriggerRow1::
	lock
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC1
	playse SE_PIN
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
	delay 60
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveLeft4
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveLeft3
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveLeft2
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveLeft1
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveLeft0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 6
	release
	end

OlivineCity_Gym_EventScript_MoveLeft0::
	turnobject VAR_TEMP_0, DIR_WEST
	return

OlivineCity_Gym_EventScript_MoveLeft1::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft2::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft3::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft4::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_Text_Gent:
	.string "{JPN}うむやはりきたんだね！\p"
	.string "{JPN}ジムリーダーのために\n"
	.string "{JPN}ちからをかしてくれたきみだが\l"
	.string "{JPN}ジムはジムだ！\p"
	.string "{JPN}しっかりたたかってきたまえ！$"
OlivineCity_Gym_Text_Gent2:
	.string "{JPN}さすがだな！そのちょうしで\n"
	.string "{JPN}かくちをまわってみるといい\p"
	.string "{JPN}せっかくなみのりがあるなら\n"
	.string "{JPN}いかりのみずうみにいってみると\l"
	.string "{JPN}いいかもしれないな！$"
OlivineCity_Gym_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Lass2
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Lass2::
	msgbox OlivineCity_Gym_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_TriggerRow2::
	lock
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC2
	playse SE_PIN
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
	delay 60
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveRight0
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveRight1
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveRight2
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveRight3
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveRight4
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 7
	release
	end

OlivineCity_Gym_EventScript_MoveRight0::
	turnobject VAR_TEMP_0, DIR_EAST
	return

OlivineCity_Gym_EventScript_MoveRight1::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight2::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight3::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight4::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_Text_Lass:
	.string "{JPN}ふふっあなたのじつりょくは\n"
	.string "{JPN}とうだいでみせてもらったわ\p"
	.string "{JPN}こんどはそのちからを\n"
	.string "{JPN}ミカンちゃんにぶつけるのよ\p"
	.string "{JPN}..おうえんしてるわ！$"
OlivineCity_Gym_Text_Lass2:
	.string "{JPN}みごとなものね..\p"
	.string "{JPN}それだけのちからがあるなら\n"
	.string "{JPN}もっとうえをめざすべきよ\p"
	.string "{JPN}あなたチョウジタウンには\n"
	.string "{JPN}もういってみた？$"
OlivineCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineCity_Gym_EventScript_GymGuideSick
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_GymGuideAfter
	msgbox OlivineCity_Gym_Text_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_GymGuideSick::
	msgbox OlivineCity_Gym_Text_GymGuidePreText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_GymGuideAfter::
	msgbox OlivineCity_Gym_Text_GymGuideWinText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_Text_GymGuideText:
	.string "{JPN}ミカンはあたらしくはっけん\nされたはがねタイプをつかう！\pかのじょにはふたひきの\nエースがいるんだ！\pいっぴきめはこうげきりょくを\nあげるきんぞくのむしポケモン！\pほのおでダメージをあたえられる\nがつよいこうげきにたえることも！\pにひきめはおおきなてつの\nへびでつよいわざをもってる！\pちゅういしてかかれ！\pのろそうにみえるがすばやさで\nさきてをうつすがたを\lみたことがあるぞ！$"
OlivineCity_Gym_Text_GymGuideWinText:
	.string "{JPN}いやあすごかったな\n"
	.string "{JPN}はがねタイプ..\l"
	.string "{JPN}ひばなをちらすたたかいを\l"
	.string "{JPN}みせてもらったぞ！$"
OlivineCity_Gym_Text_GymGuidePreText:
	.string "{JPN}ジムリーダーのミカンかい？\p"
	.string "{JPN}とうだいのポケモンのぐあいが\n"
	.string "{JPN}あんまりよくないらしくて\l"
	.string "{JPN}ようすをみにいってるぜ\p"
	.string "{JPN}ほんとうにつよいトレーナーは\n"
	.string "{JPN}つよさとどうじにやさしさも\l"
	.string "{JPN}かねそなえているものなんだな..$"
OlivineCity_Gym_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Jasmine_Defeated
	msgbox OlivineCity_Gym_Text_JasmineSteelTypeIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_CianwoodCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_MahogCheckCianwood
	goto OlivineCity_Gym_EventScript_Jasmine_Battle1

OlivineCity_Gym_EventScript_JasmineVictory::
	message OlivineCity_Gym_Text_ReceivedMineralBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox OlivineCity_Gym_Text_JasmineBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE06_GET
	setflag FLAG_DEFEATED_OLIVINE_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_IRON_TAIL
	msgbox OlivineCity_Gym_Text_JasmineIronTailSpeech, MSGBOX_DEFAULT
	setvar VAR_OLIVINE_CITY_STATE, 8
	closemessage
	release
	end

OlivineCity_Gym_EventScript_CianwoodCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2

OlivineCity_Gym_EventScript_MahogCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2
	
OlivineCity_Gym_EventScript_Jasmine_Battle1::
	trainerbattle_no_intro TRAINER_JASMINE_1, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Battle2::
	trainerbattle_no_intro TRAINER_JASMINE_1_2, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Battle3::
	trainerbattle_no_intro TRAINER_JASMINE_1_3, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Defeated::
	msgbox OlivineCity_Gym_Text_JasmineGoodLuck, MSGBOX_DEFAULT
	closemessage
	release
	end


OlivineCity_Gym_Text_JasmineSteelTypeIntro:
	.string "{JPN}ミカン: ...とうだいでは\nありがとうございました\l"
	.string "{JPN}でもしょうぶはべつですよ\p"
	.string "{JPN}あらためてじこしょうかいします\p"
	.string "{JPN}あたしはジムリーダーのミカン\nつかうポケモンは\lシャキーン!!\p"
	.string "{JPN}は...はがねタイプです\p"
	.string "{JPN}...はがねタイプって\nごぞんじですか?\p"
	.string "{JPN}とってもかたくてつめたくて\nするどくてつつよいんですよ?\l"
	.string "{JPN}ほんとなんですよ?\p$"
OlivineCity_Gym_Text_JasmineBetterTrainer:
	.string "{JPN}ミカン: ポケモントレーナーとして\nあなたのほうがうわてみたい\l"
	.string "{JPN}つよさもやさしさもね\p"
	.string "{JPN}...ではリーグのきまりどおり\nバッジをさしあげます\p$"
OlivineCity_Gym_Text_ReceivedMineralBadge:
	.string "{JPN}{PLAYER}はミカンから\nスチールバッジをもらった!$"
OlivineCity_Gym_Text_JasmineBadgeSpeech:
	.string "{JPN}ミカン: スチールバッジは\nひとからもらったポケモンでも\l"
	.string "{JPN}レベル70までのポケモンなら\lいうことをきいてくれるように\l"
	.string "{JPN}なるんです\p"
	.string "{JPN}...あのうあとこれもどうぞ\p$"
OlivineCity_Gym_Text_JasmineIronTailSpeech:
	.string "{JPN}ミカン: そのわざマシンは\nアイアンテールというわざ...\p"
	.string "{JPN}かたいしっぽをたたきつけながら\nときどきあいてのぼうぎょを\l"
	.string "{JPN}さげることがあるんです...$"
OlivineCity_Gym_Text_JasmineGoodLuck:
	.string "{JPN}ミカン: ああの...\nあんまりうまくいえないけど\p"
	.string "{JPN}...がんばってくださいね$"
OlivineCity_Gym_Text_JasmineRematchText:
	.string "{JPN}..おめでとうジョウトチャンピオン\p{PLAYER}はとてもつよくなったのね..\pわたしはせいちょうできたかしら\pそれをたしかめてもらえる？\pわたしとさいせんしてくれる？$"
OlivineCity_Gym_Text_JasmineRematchDefeatText:
	.string "{JPN}..あなたのほうがすぐれた\nトレーナーね..つよさもやさしさも$"
OlivineCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Statue2
	msgbox OlivineCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Statue2::
	msgbox OlivineCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_Text_GymStatue:
	.string "{JPN}アサギシティポケモンジム$"
OlivineCity_Gym_Text_GymStatueCertified:
	.string "{JPN}アサギシティポケモンジム\p"
	.string "{JPN}ジムリーダーミカン\nにんていトレーナー!\l{PLAYER}$"
