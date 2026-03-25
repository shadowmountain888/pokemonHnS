LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "{JPN}わたしは ゲームデザイナー です.\p"
	.string "{JPN}おお そうですか?\n"
	.string "{JPN}ポケモンずかんを つくっているのですね?\p"
	.string "{JPN}かんせいさせるのは たいへんですが\n"
	.string "{JPN}あきらめないで がんばってください.\p"
	.string "{JPN}もし かんせいしたら ぜひ\n"
	.string "{JPN}みせに きてくださいね.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "{JPN}うわあ! すごいです!\n"
	.string "{JPN}ほんとうに すごいですよ!\p"
	.string "{JPN}このポケモンずかんは かんぺきに\n"
	.string "{JPN}うまっています! ポケモンが だいすきなんですね!\p"
	.string "{JPN}とても かんどうしました!\p"
	.string "{JPN}あなたの いぎょうを たたえて\n"
	.string "{JPN}なにか さしあげましょう!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "{JPN}ぼく? ぼくに はなしかけているの?\n"
	.string "{JPN}ぼくは プログラマー だよ.\p"
	.string "{JPN}ここの スロットって\n"
	.string "{JPN}どんなかんじなんだろうね.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "{JPN}わたしは グラフィッカー です! ホウエンの\n"
	.string "{JPN}ポケモンって おもしろいでしょう?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "{JPN}おんなのこの うきわガールって\n"
	.string "{JPN}かわいいよね?\l"
	.string "{JPN}かわいい うきわガールと\n"
	.string "{JPN}たたかうなんて...\p"
	.string "{JPN}うひょー! さいこうだよ!\p"
	.string "{JPN}それから ふたごちゃん!\nかわいくない?\lふたごちゃんと\n2たい2で たたかうなんて...\pうひょー!\nたまらなく たのしいよ!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "{JPN}うみかぜが こころに しみるわ.\n"
	.string "{JPN}ここって きもちいいのね!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "{JPN}いつ どこで だれに\n"
	.string "{JPN}しょうぶを いどまれるか わからない.\p"
	.string "{JPN}だから いえを でるときは いつも\n"
	.string "{JPN}ゲームボーイアドバンス を もっていくの.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "{JPN}エニシダ: ... ... ... ... ...\l"
	.string "{JPN}... ... ... ... ... zzz...\p"
	.string "{JPN}... ... ... ... ... はっ?!\n"
	.string "{JPN}あ ごめん ごめん!\n"
	.string "{JPN}うとうと してたよ!\p"
	.string "{JPN}ポケモン コンテストって\n"
	.string "{JPN}やつを みにきたんだ\p"
	.string "{JPN}たしかに けっこう\n"
	.string "{JPN}おもしろそうだけど...\p"
	.string "{JPN}ぼくは げんりしゅぎしゃ\n"
	.string "{JPN}でね バトルと つよい\l"
	.string "{JPN}トレーナーが すきなんだ\p"
	.string "{JPN}でも それは ぼくの\n"
	.string "{JPN}このみだからね\p{PLAYER}には ジムも\nコンテストも バトルテントも\lぜんぶ たのしんで\nもらいたいな!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "{JPN}エニシダ: コンテストで かつには\n"
	.string "{JPN}やっぱり せんりゃくが ひつようだと おもうね.\p"
	.string "{JPN}コンテストの せんりゃくを かんがえることも\n"
	.string "{JPN}よい トレーナーに なるための みちの ひとつさ.$"

