.set LOCALID_SPROUT_TOWER_SILVER, 5

SproutTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end


SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
	end


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_3F_EventScript_Potion::
	finditem ITEM_POTION
	end

SproutTower_3F_EventScript_EscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_TriggerSceneLeft::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 60
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	delay 30
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_TriggerSceneRight::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 60
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
	waitmovement 0
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_SageLi::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LI, SproutTower_Text_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_EventScript_SageLi_Beaten::
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_Movement_Silver1:
	walk_fast_up
	walk_fast_up
	step_end

SproutTower_3F_Movement_SilverLeft:
	face_down
	delay_16
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_SilverRight:
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_EscapeRope:
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

SproutTower_Text_ElderLecturesRival:
	.string "{JPN}ろうじん:おまえは たしかに\n"
	.string "{JPN}トレーナーとして うでが たつ.\p"
	.string "{JPN}やくそく どおり ひでんマシンを\n"
	.string "{JPN}わたそう.\p"
	.string "{JPN}しかし ひとこと いわせて\n"
	.string "{JPN}もらおう.ポケモンを もっと\n"
	.string "{JPN}たいせつに あつかうべきじゃ.\p"
	.string "{JPN}おまえの たたかいかたは\nあまりにも むじひすぎる.\pポケモンは せんそうの\nどうぐでは ないのじゃ...$"
SproutTower_Text_RivalOnlyCaresStrong:
	.string "{JPN}.........\p"
	.string "{JPN}...フン!\nえらそうにちょうろうなんて\lなのっているくせして\l"
	.string "{JPN}ぜんぜんはごたえないじゃないか\p"
	.string "{JPN}...とうぜんだな\nポケモンにやさしくとか\l"
	.string "{JPN}そんなあまいこといってるやつに\lオレがまけるわけがない\p"
	.string "{JPN}オレにとってだいじなのは\nつよくてかてるポケモンだけ\p"
	.string "{JPN}それいがいのポケモンなんか\nどうだっていいのさ\p$"

SproutTower_Text_RivalUsedEscapeRope:
	.string "{JPN}{RIVAL}は あなぬけのひもを\nつかった!$"

SproutTower_Text_SageLi_Seen:
	.string "{JPN}よくぞここまでまいられた!\p"
	.string "{JPN}このマダツボミのとうは\nポケモンとひとが\lあかるいみらいをきずけるか"
	.string "{JPN}\lしゅぎょうでたしかめるばしょ\p"
	.string "{JPN}そしてさいごのしれんは\nこのわたし\p"
	.string "{JPN}ではそなたとポケモンのきずな\nたしかめさせてもらいますぞ!\p$"

SproutTower_Text_SageLi_Beaten:
	.string "{JPN}ふうむ...\nそなたのたたかいかた\lじつにムダがない\p"
	.string "{JPN}それならばハヤトどのとも\nごかくにわたりあえるであろう\p"
	.string "{JPN}そして...そなたならば\nこれもつかいこなせるであろう\p"
	.string "{JPN}フラッシュというなのわざマシン\nさあもっていきなされ!\p$"

SproutTower_Text_SageLi_TakeFlash:
	.string "{JPN}ちょうろう: そなたのじつりょく\nたしかにいつわりなし...\p"
	.string "{JPN}やくそくしたとおり\nこのわざマシンをわたそう\p"
	.string "{JPN}だが...もうちいっと\nポケモンをいたわるべきですぞ\p"
	.string "{JPN}そなたのたたかいかたは\nあまりにもきびしすぎる...\p"
	.string "{JPN}ポケモンはたたかいの\nどうぐなどではないのです...\p$"

SproutTower_Text_SageLi_FlashExplain:
	.string "{JPN}フラッシュをおぼえさせれば\nどれほどくらいところでも\l"
	.string "{JPN}てらすことができますぞ\p"
	.string "{JPN}たとえばマダツボミなどに\nおぼえさせるがよいであろう...$"

SproutTower_Text_SageLi_AfterBattle:
	.string "{JPN}そなたのたびが\nみのりおおいものでありますように$"

SproutTower_Text_SageJin_Seen:
	.string "{JPN}ポケモンと ともに さとりを\n"
	.string "{JPN}ひらくため しゅぎょうちゅう!$"

SproutTower_Text_SageJin_Beaten:
	.string "{JPN}わしの しゅぎょうが\nたりなかった...$"
SproutTower_Text_SageJin_AfterBattle:
	.string "{JPN}ポケモンが つよくなると\n"
	.string "{JPN}トレーナーも つよくなる.\p"
	.string "{JPN}いや まてよ. トレーナーが\n"
	.string "{JPN}つよくなると ポケモンも\l"
	.string "{JPN}つよくなるのか.$"

SproutTower_Text_SageTroy_Seen:
	.string "{JPN}あなたが ポケモンを\n"
	.string "{JPN}どれほど しんらいしているか\lみせてもらいましょう.$"

SproutTower_Text_SageTroy_Beaten:
	.string "{JPN}はい あなたの しんらいは\nほんものです!$"

SproutTower_Text_SageTroy_AfterBattle:
	.string "{JPN}ちょうろうのところまで\nもう ちかいですよ.$"

SproutTower_Text_SageNeal_Seen:
	.string "{JPN}ちょうろうの ひでんマシンは\n"
	.string "{JPN}まっくらやみも てらすのです.$"

SproutTower_Text_SageNeal_Beaten:
	.string "{JPN}あかるいのは わたしの\nあたまでした!$"

SproutTower_Text_SageNeal_AfterBattle:
	.string "{JPN}あなたの たびに ひかりが\n"
	.string "{JPN}さしますように.$"

SproutTower_Text_3F_Painting:
	.string "{JPN}マダツボミの ちからづよい\n"
	.string "{JPN}えが かかれている.$"
