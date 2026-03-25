Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_BillS_HOUSE
	end

Route114_LanettesHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_Bill, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_BILL
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_Bill
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "{JPN}マサキ: あっ! {PLAYER}{KUN}!\p"
	.string "{JPN}さんらんしてて ごめんね...\n"
	.string "{JPN}けんきゅうに むちゅうになると\l"
	.string "{JPN}こんなふうに なっちゃうんだ...\p"
	.string "{JPN}はずかしいなあ... これとひきかえに\n"
	.string "{JPN}ないしょにしておいて もらえる?$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "{JPN}わたしの ポケモンほぞん\n"
	.string "{JPN}システムについて\p"
	.string "{JPN}アドバイスを させて\n"
	.string "{JPN}もらえませんか?\pボックスを せいりして\nどの ポケモンが はいってるか\lわかるように したほうが\lいいですよ$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "{JPN}マサキの けんきゅうノートだ\n"
	.string "{JPN}ボックスについての じょうほうが\l"
	.string "{JPN}かかれている\p"
	.string "{JPN}ボックスは ひとつにつき\n"
	.string "{JPN}30ひきの ポケモンを\l"
	.string "{JPN}ほぞんできる せっけいにする\pそれぞれの トレーナーは\nパソコンシステムに\l450ひきの ポケモンを\lほぞんできるように する\pつづきを よみますか?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "{JPN}ポケモンを せいりしやすく\n"
	.string "{JPN}するため マーキングシステムを\l"
	.string "{JPN}ついかする ひつようがある\p"
	.string "{JPN}それぞれの ボックスの なまえと\n"
	.string "{JPN}かべがみの デザインを\l"
	.string "{JPN}へんこうできるように して\lほぞんされた ポケモンを\lよろこばせる\pつづきを よみますか?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "{JPN}ポケモンを ほぞんするとき\n"
	.string "{JPN}さいごに しらべた ボックスに\l"
	.string "{JPN}おくられる ようにする\p"
	.string "{JPN}その ボックスが いっぱいなら\n"
	.string "{JPN}うけとった ポケモンは\l"
	.string "{JPN}つぎの ボックスに ほぞんされる\p"
	.string "{JPN}つまり ボックスを しらべると\nじどうてきに そのボックスが\lポケモンの おくりさきとして\lせんたくされる$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{JPN}{PLAYER}は ノートを とじた$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "{JPN}パソコンに だれかからの\n"
	.string "{JPN}メールがきている.\p"
	.string "{JPN}... ... ... ... ... ... ...\p"
	.string "{JPN}きみの ボックスシステムは\n"
	.string "{JPN}ぼくのより べんりだね.\p"
	.string "{JPN}つかいやすくて たのしめる\n"
	.string "{JPN}きのうが たくさん ついてる.\p"
	.string "{JPN}その かいはつに かかわれたこと\n"
	.string "{JPN}を ほこりに おもってるよ.\p"
	.string "{JPN}これからも ボックスシステムの\n"
	.string "{JPN}けんきゅうを つづけてほしい.\p"
	.string "{JPN}マサキより\n"
	.string "{JPN}... ... ... ... ... ... ... ...$"
