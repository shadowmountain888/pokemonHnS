UnionCave_1F_MapScripts::
	.byte 0


UnionCave_1F_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	end


UnionCave_1F_EventScript_HikerRussell::
	trainerbattle_single TRAINER_RUSSELL, UnionCave_1F_Text_HikerRussellSeen, UnionCave_1F_Text_HikerRussellBeaten
	msgbox UnionCave_1F_Text_HikerRussellAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_PokemaniacLarry::
	trainerbattle_single TRAINER_LARRY, UnionCave_1F_Text_PokemaniacLarrySeen, UnionCave_1F_Text_PokemaniacLarryBeaten
	msgbox UnionCave_1F_Text_PokemaniacLarryAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_HikerDaniel::
	trainerbattle_single TRAINER_DANIEL, UnionCave_1F_Text_HikerDanielSeen, UnionCave_1F_Text_HikerDanielBeaten
	msgbox UnionCave_1F_Text_HikerDanielAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherBill::
	trainerbattle_single TRAINER_BILL, UnionCave_1F_Text_FirebreatherBillSeen, UnionCave_1F_Text_FirebreatherBillBeaten
	msgbox UnionCave_1F_Text_FirebreatherBillAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherRay::
	trainerbattle_single TRAINER_RAY, UnionCave_1F_Text_FirebreatherRaySeen, UnionCave_1F_Text_FirebreatherRayBeaten
	msgbox UnionCave_1F_Text_FirebreatherRayAfter, MSGBOX_AUTOCLOSE
	end	

UnionCave_1F_EventScript_Item_Potion::
	finditem ITEM_POTION
	end

UnionCave_1F_EventScript_Item_GreatBall::
	finditem ITEM_GREAT_BALL
	end

UnionCave_1F_EventScript_Item_Xattack::
	finditem ITEM_X_ATTACK
	end

UnionCave_1F_EventScript_Item_Awakening::
	finditem ITEM_AWAKENING
	end

UnionCave_1F_Text_HikerRussellSeen:
	.string "{JPN}きみは ヒワダタウンに\n"
	.string "{JPN}むかってるのかい?\p"
	.string "{JPN}わしの ポケモンで きみが\nたたかうのに じゅうぶんか\nためして みよう!$"

UnionCave_1F_Text_HikerRussellBeaten:
	.string "{JPN}おお おお おお!$"

UnionCave_1F_Text_HikerRussellAfter:
	.string "{JPN}よし それなら きめた!\p"
	.string "{JPN}わしの ポケモンが つよくなる\n"
	.string "{JPN}まで ここを でないぞ!$"

UnionCave_1F_Text_PokemaniacLarrySeen:
	.string "{JPN}おれは ポケモンを さがして\n"
	.string "{JPN}あちこち たびしてるんだ\p"
	.string "{JPN}きみも ポケモンを さがしてる\n"
	.string "{JPN}のか?\pじゃあ きみは おれの\nコレクション ライバルだな!$"

UnionCave_1F_Text_PokemaniacLarryBeaten:
	.string "{JPN}ああ かわいそうな おれの\nポケモン...$"
UnionCave_1F_Text_PokemaniacLarryAfter:
	.string "{JPN}まいしゅう きんようびに\n"
	.string "{JPN}どうくつの おくから ポケモンの\nなきごえが きこえるぞ$"

UnionCave_1F_Text_HikerDanielSeen:
	.string "{JPN}おおっ! びっくりした!\p"
	.string "{JPN}こんな ところで ひとに あうとは\nおもわなかった!$"

UnionCave_1F_Text_HikerDanielBeaten:
	.string "{JPN}おおっ! だいはいぼく だった!$"

UnionCave_1F_Text_HikerDanielAfter:
	.string "{JPN}ヤドンのしっぽを だまされて\n"
	.string "{JPN}かってしまったよ\p"
	.string "{JPN}かわいそうな ポケモンだ$"

UnionCave_1F_Text_FirebreatherBillSeen:
	.string "{JPN}ズバットの ちょうおんぱで\n"
	.string "{JPN}おれの ポケモンが こんらん\n"
	.string "{JPN}しっぱなしだ\pほんとうに こまってるんだ!$"

UnionCave_1F_Text_FirebreatherBillBeaten:
	.string "{JPN}ほのおが きえちゃった!$"

UnionCave_1F_Text_FirebreatherBillAfter:
	.string "{JPN}しゅうまつには どうくつの おくから\n"
	.string "{JPN}ふしぎな うなりごえが きこえるよ$"

UnionCave_1F_Text_FirebreatherRaySeen:
	.string "{JPN}あかりが あれば どうくつは\n"
	.string "{JPN}こわくない\n"
	.string "{JPN}つよければ ポケモンは こわくない$"

UnionCave_1F_Text_FirebreatherRayBeaten:
	.string "{JPN}フラッシュ!$"

UnionCave_1F_Text_FirebreatherRayAfter:
	.string "{JPN}この どうくつを てらしてるのは\n"
	.string "{JPN}おれの ポケモンの ほのおだ$"
