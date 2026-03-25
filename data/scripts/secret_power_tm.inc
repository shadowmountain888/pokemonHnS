Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "{JPN}えっ なにを してるかって?\p"
	.string "{JPN}ポケモンの わざを つかって\n"
	.string "{JPN}ここに ぼくだけの へやを\l"
	.string "{JPN}つくろうと おもってね!\p"
	.string "{JPN}そうだっ この わざマシンを あげるから\n"
	.string "{JPN}きみも つくって みるかい?$"

Route111_Text_ExplainSecretPower:
	.string "{JPN}ツルが おちそうな きにむかって\n"
	.string "{JPN}ひみつのちからを つかってごらん!\l"
	.string "{JPN}ツルが おちてきて きのうえに のぼれるよ!\p"
	.string "{JPN}それでね うえには ひろいへやが あるから\n"
	.string "{JPN}ぼくは そこに すきなものを おくんだ!\l"
	.string "{JPN}じぶんだけの ひみつのへや...\l"
	.string "{JPN}そう ひみつきちさ!\l"
	.string "{JPN}きみも つくると いいよー\p"
	.string "{JPN}そうそう ひみつきちを つくれる ばしょは\n"
	.string "{JPN}きのうえ だけじゃ ないよ!\p"
	.string "{JPN}ちいさな くぼみがある かべなんかにも\n"
	.string "{JPN}ひみつのちからを つかって みるといいよ!\p"
	.string "{JPN}ぼくも ほかの ばしょを さがして みるね\n"
	.string "{JPN}それじゃ!$"

Route111_Text_DontWantThis:
	.string "{JPN}そう いらないんだ...\n"
	.string "{JPN}ほしくなったら また こえかけてね!$"

Route111_Text_DontHaveAnyRoom:
	.string "{JPN}あれ?\n"
	.string "{JPN}それいじょうは もてない みたいだよ\p"
	.string "{JPN}また こんど とりに きてね!$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_GARBAGEFLAG
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
