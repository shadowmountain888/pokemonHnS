Route27_House_MapScripts::
	.byte 0

Route27_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_TM_SANDSTORM, Route27_House_EventScript_WomanBeforeGiven
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanBeforeGiven::
	msgbox SandstormHouse_Text_Woman1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, Route27_House_EventScript_WomanHighFriendship
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_QuestionMark
	waitmovement 0
	msgbox SandstormHouse_Text_DisloyalMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanHighFriendship::
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER ContestHall_Movement_Heart
	waitmovement 0
	msgbox SandstormHouse_Text_LoyalMon, MSGBOX_DEFAULT
	giveitem ITEM_TM_SANDSTORM
	setflag FLAG_GOT_TM_SANDSTORM
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_Movement_FollowerJump:
	jump_in_place_down
	jump_in_place_down
	step_end

SandstormHouse_Text_Woman1:
    .string "{JPN}ポケモンを つれて\n"
	.string "{JPN}どこへ いくの?\p"
    .string "{JPN}ポケモンリーグ?\p"
	.string "{JPN}あなたの ポケモンは\n"
    .string "{JPN}かてるほど ちゅうじつなの?\p"
	.string "{JPN}ちょっと みせて...$"
SandstormHouse_Text_LoyalMon:
    .string "{JPN}あ! きみの ポケモンは\n"
	.string "{JPN}きみを とても しんらい\l"
    .string "{JPN}しているね.\p"
	.string "{JPN}よい トレーナーを みると\nうれしく なるよ.\pはい. たびの おくりものだ.$"

SandstormHouse_Text_TM37Description:
    .string "{JPN}わざマシン37は すなあらしだ.\p"
	.string "{JPN}バトルちゅうの りょうほうに\n"
    .string "{JPN}ダメージを あたえる わざだよ.\p"
	.string "{JPN}じょうきゅうしゃ むけの わざだ.\p"
    .string "{JPN}ちょうせん する きが あるなら\nつかって みたまえ. がんばれ!$"

SandstormHouse_Text_DisloyalMon:
    .string "{JPN}もっと しんらい して\n"
	.string "{JPN}もらわないと たいへんだぞ.\p"
    .string "{JPN}しんらいが ポケモンと\n"
	.string "{JPN}トレーナーを つなぐ きずななのだ.$"


