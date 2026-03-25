MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_DusknoirMisdreavusEvo::
	msgbox MtPyre_1F_DusknoirMisdreavusEvo_Text, MSGBOX_NPC
	end

MtPyre_1F_DusknoirMisdreavusEvo_Text:
	.string "{JPN}やせいの ヨマワルは ときどき\n"
	.string "{JPN}のろいのおふだを もっている.\l"
	.string "{JPN}なぜだろう? なにに つかうのか?\p"
	.string "{JPN}もしかしたら しんかに\n"
	.string "{JPN}つかうのかもしれない.\pわかっているのは ムウマが\nよるに それを もっていると\lしんかする ということだ.$"

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "{JPN}やまのしゃめんには\n"
	.string "{JPN}いろんなせいめいが\n"
	.string "{JPN}さまよっているのう...\p"
	.string "{JPN}なにがおこるか\nわからんからの.\nこれをもっていきなさい.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "{JPN}ポケモンに その\n"
	.string "{JPN}きよめのおふだを もたせなさい.\p"
	.string "{JPN}やせいの ポケモンを\nよけるのに やくだつでしょう.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "{JPN}しんだ ポケモンの たましいに\n"
	.string "{JPN}おまいりに きたのですね?\p"
	.string "{JPN}あなたは ポケモンを とても\nたいせつに している のですね.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "{JPN}ここは わたしの\n"
	.string "{JPN}ジグザグマの\nさいごのやすらぎのばしょ.\pたいせつにしていたのじゃ...$"
