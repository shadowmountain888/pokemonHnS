PewterCity_Gym_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	giveitem ITEM_TM_EARTHQUAKE
	setflag FLAG_BADGE09_GET
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DIGLETT_BROCK
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "{JPN}ジョウトから\n"
	.string "{JPN}ちょうせんとはめずらしい！\p"
	.string "{JPN}おれはニビポケモンジム\n"
	.string "{JPN}リーダーのタケシ！\l"
	.string "{JPN}いわタイプのエキスパートさ！\p"
	.string "{JPN}ちょっとやそっとのこうげきじゃ\n"
	.string "{JPN}おれのポケモンたちはへいき\l"
	.string "{JPN}いたくもかゆくもないぜ！\p"
	.string "{JPN}かかってこい！$"
PewterCity_Gym_Text_Brock_WinLoss:
	.string "{JPN}..まもりをうわまわる\n"
	.string "{JPN}きょうれつなこうげき..\l"
	.string "{JPN}おれのよそういじょうだ..！\p"
	.string "{JPN}さあこのバッジを\n"
	.string "{JPN}もっていってくれ！$"
PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{JPN}{PLAYER}はタケシから\n"
	.string "{JPN}グレーバッジをもらった！$"
PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "{JPN}ブロック: {PLAYER} ありがとう.\n"
	.string "{JPN}ちょっと くやしいけど\l"
	.string "{JPN}たのしい たたかいだったよ.\p"
	.string "{JPN}その グレーバッジが きみの\n"
	.string "{JPN}ポケモンを もっと つよく\lしてくれるだろう.$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "{JPN}よのなかはひろいな..\n"
	.string "{JPN}こんなにつよいトレーナーが\l"
	.string "{JPN}まだまだたくさんいるんだ\p"
	.string "{JPN}おれももっともっと\n"
	.string "{JPN}つよいトレーナーになるよ！$"
PewterCity_Gym_Text_CamperJerry_Seen:
	.string "{JPN}このジムの トレーナーは\n"
	.string "{JPN}いわタイプの ポケモンを\l"
	.string "{JPN}つかうんだ.\p"
	.string "{JPN}いわタイプは ぼうぎょが\n"
	.string "{JPN}たかいんだよ.\pたたかいは ながびくかも\nしれない.じゅんびは\lできてるかい?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "{JPN}I have to win these battles...$"
PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "{JPN}おい きみ! ジョウトの\n"
	.string "{JPN}トレーナー! ブロックは\l"
	.string "{JPN}つよいぞ.\pまじめに たたかわないと\nひどいめに あうからな!$"

PewterCity_Gym_Text_Guide:
	.string "{JPN}おーす！\n"
	.string "{JPN}みらいのレジェンド！\p"
	.string "{JPN}みたところ..\n"
	.string "{JPN}ちょうしはよさそうだな！\p"
	.string "{JPN}カントーのジムリーダーと\n"
	.string "{JPN}たたかってるかい？\p"
	.string "{JPN}ジョウトにまけずおとらず\n"
	.string "{JPN}てごわいヤツらだぜ！$"
PewterCity_Gym_Text_Guide_Win:
	.string "{JPN}さすがはみらいのレジェンド！\n"
	.string "{JPN}あぶなげないたたかいだったぜ！\l"
	.string "{JPN}かんどうしたよいやホント！$"
PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "{JPN}ニビ ポケモンジム\n"
	.string "{JPN}リーダー: ブロック\p"
	.string "{JPN}かった トレーナー:\n"
	.string "{JPN}グリーン レッド$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "{JPN}ニビ ポケモンジム\n"
	.string "{JPN}リーダー: ブロック\p"
    .string "{JPN}かった トレーナー:\n"
	.string "{JPN}グリーン レッド {PLAYER}$"


