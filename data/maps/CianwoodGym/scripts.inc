.set LOCALID_CIANWOOD_CHUCK, 1
.set LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, 10
.set LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, 9

CianwoodGym_MapScripts::
	.byte 0


CianwoodGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Statue2
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_Statue2::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_GymStatue:
	.string "{JPN}タンバシティポケモンジム$"

CianwoodGym_Text_GymStatueCertified:
	.string "{JPN}タンバシティポケモンジム\p"
	.string "{JPN}ジムリーダーシジマ\nにんていトレーナー!\l{PLAYER}$"

CianwoodGym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_CHUCK, CianwoodGym_EventScript_ChuckAtDojo
	goto_if_set FLAG_VISITED_VERMILION_CITY, CianwoodGym_EventScript_ChuckGotoDojo
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Chuck_Defeated
	msgbox CianwoodGym_Text_ChuckIntro1, MSGBOX_DEFAULT
	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckLeft
	waitmovement 0
	message CianwoodGym_Text_ChuckIntro2
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0

	delay 20

	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckRight
	waitmovement 0
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	waitmessage
	turnobject LOCALID_CIANWOOD_CHUCK, DIR_SOUTH
	msgbox CianwoodGym_Text_ChuckIntro3, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_OlivineCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_MahogCheckOlivine
	goto CianwoodGym_EventScript_Chuck_Battle1

CianwoodGym_EventScript_ChuckVictory::
	message CianwoodGym_Text_GetStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodGym_Text_ChuckBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_CIANWOOD_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_FOCUS_PUNCH
	msgbox CianwoodGym_Text_ChuckTMSpeech, MSGBOX_DEFAULT
	setvar VAR_GETFLY, 1
	setrespawn HEAL_LOCATION_CIANWOOD_CITY
	closemessage
	release
	end

CianwoodGym_EventScript_ChuckGotoDojo::
	msgbox CianwoodGym_Text_ChuckGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_CHUCK
	release
	end

CianwoodGym_Text_ChuckGotoDojo:
	.string "{JPN}ワハハハ {PLAYER}！\nいま しゅぎょうちゅうだ！\pもういちど しょうぶしたいなら\nヤマブキの かくとうどうじょうへ！$"
CianwoodGym_EventScript_ChuckAtDojo::
	msgbox CianwoodGym_Text_ChuckAtDojo, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_ChuckAtDojo:
	.string "{JPN}どうじょうで まってるぞ！\nワハハハハハ$"
CianwoodGym_EventScript_OlivineCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_MahogCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2
	
CianwoodGym_EventScript_Chuck_Battle1::
	trainerbattle_no_intro TRAINER_CHUCK_1, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle2::
	trainerbattle_no_intro TRAINER_CHUCK_1_2, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle3::
	trainerbattle_no_intro TRAINER_CHUCK_1_3, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Defeated::
	msgbox CianwoodGym_Text_ChuckAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Movement_ChuckLeft:
	jump_in_place_left
	step_end

CianwoodGym_Movement_ChuckRight:
	jump_in_place_right
	step_end

CianwoodGym_Text_ChuckIntro1:
	.string "{JPN}シジマ: ぬおぉぉー!\nはげしくながれおちるたきが\l"
	.string "{JPN}わしのあたまのうえに\lズドドドド...ってコラー!\p"
	.string "{JPN}かってにみずをとめるなー!\nわしのしゅぎょうの\lじゃまをしおってー!\p"
	.string "{JPN}いっとくがわしはつよいぞ!\nこうやってまいにち\l"
	.string "{JPN}たきにうたれているからな!\p"
	.string "{JPN}なに?\nポケモンとはかんけいない?\p"
	.string "{JPN}.........\nそれもそうだ\p"
	.string "{JPN}.........\n.........\p"
	.string "{JPN}ではしょうぶといくかぁ!\p$"
CianwoodGym_Text_ChuckIntro2:
	.string "{JPN}ううー\n.........\p"
	.string "{JPN}どりゃああ!!$"

CianwoodGym_Text_ChuckIntro3:
	.string "{JPN}どうだ!おじけづいたろ!\p"
	.string "{JPN}なにポケモンとはかんけいない?\nそれもそうだ!\l"
	.string "{JPN}ではしょうぶといくかあ!\p$"

CianwoodGym_Text_ChuckLoss:
	.string "{JPN}シジマ: うーむわしが\nまけるとは...こりゃまいった!\p"
	.string "{JPN}よーしっ!このショックバッジは\nおまえにふさわしい!\p$"

CianwoodGym_Text_GetStormBadge:
	.string "{JPN}{PLAYER}はシジマから\nショックバッジをもらった!$"
CianwoodGym_Text_ChuckBadgeSpeech:
	.string "{JPN}シジマ: ショックバッジがあれば\nすでにいったことのあるまちへ\l"
	.string "{JPN}そらをとぶでとんでいけるぞ!\p"
	.string "{JPN}うむっついでだ\nこいつももってけ!\p$"
CianwoodGym_Text_ChuckTMSpeech:
	.string "{JPN}シジマ: わざマシン01のなかみは\nきあいパンチ!!\p"
	.string "{JPN}さきにこうげきをうけると\nこちらのこうげきがだせなくなるが\p"
	.string "{JPN}あてられればぜつだいな\nいりょくをはっきするぞ!$"
CianwoodGym_Text_ChuckAfter:
	.string "{JPN}シジマ: わはは!\nわしたのしかったよ!\p"
	.string "{JPN}でもまけはまけだからな\nきょうから24じかんとっくんだ!$"

CianwoodGym_Text_ChuckRematch:
	.string "{JPN}ワハハハ！ ジョウトの チャンピオン！\pまた しょうぶしにきたな！\pうでを あげたようだな！\pどちらが つよいか ためそうぜ？$"
CianwoodGym_Text_ChuckRematchDefeat:
	.string "{JPN}なんだと？ また まけた？\nそんな..$"
CianwoodGym_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI CianwoodGym_Text_BlackbeltYoshiSeen, CianwoodGym_Text_BlackbeltYoshiBeaten
	msgbox CianwoodGym_Text_BlackbeltYoshiAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltYoshiSeen:
	.string "{JPN}おれと ポケモンは ゆうじょうで\nむすばれているんだ\pそのきずなは ぜったい きれない！$"
CianwoodGym_Text_BlackbeltYoshiBeaten:
	.string "{JPN}うそだろ！$"
CianwoodGym_Text_BlackbeltYoshiAfter:
	.string "{JPN}きみも ポケモンと\nつよいきずなを もってるんだな！$"
CianwoodGym_EventScript_Lao::
	trainerbattle_single TRAINER_LAO CianwoodGym_Text_BlackbeltLaoSeen, CianwoodGym_Text_BlackbeltLaoBeaten
	msgbox CianwoodGym_Text_BlackbeltLaoAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLaoSeen:
	.string "{JPN}ぶどうかはなにもこわくない！$"
CianwoodGym_Text_BlackbeltLaoBeaten:
	.string "{JPN}これはショックだ！$"
CianwoodGym_Text_BlackbeltLaoAfter:
	.string "{JPN}かくとうポケモンは\nエスパーがにがてなんだ.$"
CianwoodGym_EventScript_Nob::
	trainerbattle_single TRAINER_NOB CianwoodGym_Text_BlackbeltNobSeen, CianwoodGym_Text_BlackbeltNobBeaten
	msgbox CianwoodGym_Text_BlackbeltNobAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltNobSeen:
	.string "{JPN}ことばはむだだ\nこぶしでかたろうぜ！$"
CianwoodGym_Text_BlackbeltNobBeaten:
	.string "{JPN}ぐっ...!$"
CianwoodGym_Text_BlackbeltNobAfter:
	.string "{JPN}まけた！ことばもでない！$"
CianwoodGym_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG CianwoodGym_Text_BlackbeltLungSeen, CianwoodGym_Text_BlackbeltLungBeaten
	msgbox CianwoodGym_Text_BlackbeltLungAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLungSeen:
	.string "{JPN}もえたぎるこぶしで\nきみのポケモンをこなごなに！$"
CianwoodGym_Text_BlackbeltLungBeaten:
	.string "{JPN}こなごなになったのはおれだ！$"
CianwoodGym_Text_BlackbeltLungAfter:
	.string "{JPN}ポケモンがまけた.\nお.おれのプライドが.$"