MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "{JPN}あいしい エネコの おもいで...\n"
	.string "{JPN}かんがえると なみだが あふれる...$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "{JPN}いたたた... ここは あちこちに\n"
	.string "{JPN}あながあいて いるんだ.\p"
	.string "{JPN}きがつかないで うえのかいから\n"
	.string "{JPN}おちてしまった.$"

MtPyre_2F_Text_MarkIntro:
	.string "{JPN}おい!ポケモンを さがしてるのか?\n"
	.string "{JPN}おれの あとから きやがって! しつれいだぞ!$"

MtPyre_2F_Text_MarkDefeat:
	.string "{JPN}うわあああ!\n"
	.string "{JPN}ごめん ゆるしてくれ たのむ!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "{JPN}ひとが あまり こないから\n"
	.string "{JPN}めずらしい ポケモンが いると おもったんだ$"

MtPyre_2F_Text_LukeIntro:
	.string "{JPN}ルーク:きもだめしで きたんだ\p"
	.string "{JPN}へへ かっこいい ところを みせたら\n"
	.string "{JPN}かのじょが おれに ほれるぜ ぜったい!\p"
	.string "{JPN}よし! おまえを やっつけて\n"
	.string "{JPN}かっこいい ところを みせてやる!$"

MtPyre_2F_Text_LukeDefeat:
	.string "{JPN}ルーク:あちゃー!$"

MtPyre_2F_Text_LukePostBattle:
	.string "{JPN}ルーク:まあ まけたけど だいじょうぶ!\n"
	.string "{JPN}きみの そばに いるから\l"
	.string "{JPN}この きもだめし のりきろうぜ!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "{JPN}ルーク:おれと しょうぶするなら\n"
	.string "{JPN}ポケモンを もっと つれて こいよ\p"
	.string "{JPN}そうじゃないと かのじょに\n"
	.string "{JPN}かっこいい ところ みせられないだろ!$"

MtPyre_2F_Text_DezIntro:
	.string "{JPN}デズ:かれしと きもだめしに きたの\p"
	.string "{JPN}ほんとうに こわいけど かれしと\n"
	.string "{JPN}いっしょだから だいじょうぶ\p"
	.string "{JPN}そうだ!かれしに かっこよく\n"
	.string "{JPN}あなたを たおして もらうわ!$"
	.string ""

MtPyre_2F_Text_DezDefeat:
	.string "{JPN}デズ:わあああ!こわい!$"

MtPyre_2F_Text_DezPostBattle:
	.string "{JPN}デズ:わたしたち らぶらぶだから\n"
	.string "{JPN}まけても きに しないの!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "{JPN}デズ:わたしたちに ちょうせんするなら\n"
	.string "{JPN}ポケモンを 2ひき いじょう つれて きて\p"
	.string "{JPN}わたしの かれし つよいのよ\n"
	.string "{JPN}ポケモン 1ぴきじゃ ぜんぜん だめ$"

MtPyre_2F_Text_LeahIntro:
	.string "{JPN}みなれない おかた...\n"
	.string "{JPN}なにかが おこるまえに さりなさい!$"

MtPyre_2F_Text_LeahDefeat:
	.string "{JPN}ふむ...\n"
	.string "{JPN}あなたは つよい.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "{JPN}わたしの いえけは\n"
	.string "{JPN}ひいおばあちゃんの だいから\n"
	.string "{JPN}ここで トレーナーを して いる...\p"
	.string "{JPN}このやまを まもるのが\nわたしの つとめ...$"
MtPyre_2F_Text_ZanderIntro:
	.string "{JPN}きゃああああ!\n"
	.string "{JPN}こわいよう!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "{JPN}いやああああ!\n"
	.string "{JPN}きが くるいそうだ!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "{JPN}なにかが うごくのを みるたびに\n"
	.string "{JPN}びっくりしてしまう...\p"
	.string "{JPN}ここに しゅぎょうに きたのは\nまちがいだった...$"
