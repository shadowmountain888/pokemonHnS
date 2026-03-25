.set LOCALID_CINNABAR_BLUE, 1
.set LOCALID_CINNABAR_BLAINE, 12

CinnabarIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	end

CinnabarIsland_EventScript_Blaine::
    lock
    faceplayer
    msgbox CinnabarIsland_Text_Blaine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CINNABAR_BLAINE
    removeobject LOCALID_CINNABAR_BLAINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BLAINE
    release
    end

CinnabarIsland_Text_Blaine:
    .string "{JPN}カツラ: グレンジムを\n"
	.string "{JPN}さいけんするまでは\l"
	.string "{JPN}ぜったいに あきらめないぞ!\p"
	.string "{JPN}それまでは かくとうどうじょうに\n"
	.string "{JPN}いるからな!$"



CinnabarIsland_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq VAR_NUM_BADGES, 15, CinnabarIsland_EventScript_BlueActive
	msgbox CinnabarIsland_Text_BlueBefore, MSGBOX_NPC
	release
	end

CinnabarIsland_EventScript_BlueActive::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CINNABAR_BLUE
	removeobject LOCALID_CINNABAR_BLUE
	clearflag FLAG_HIDE_VIRIDIAN_BLUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


CinnabarIsland_Text_BlueBefore:
	.string "{JPN}きみは だれだい?\p"
	.string "{JPN}まあ みたところ\n"
	.string "{JPN}トレーナーの ようだが...\p"
	.string "{JPN}おれの なまえは グリーン.\p"
	.string "{JPN}いちど チャンピオンに\n"
	.string "{JPN}なったことが あるんだ...\p"
	.string "{JPN}ほんの みじかいあいだ\n"
	.string "{JPN}だけど な...\p"
	.string "{JPN}あの おせっかいな\n"
	.string "{JPN}レッドに やられちまった...\p"
	.string "{JPN}ところで なんの ようだ?\n"
	.string "{JPN}おれに ちょうせん でも\l"
	.string "{JPN}するつもりか?\p"
	.string "{JPN}...くやしいが いまは\n"
	.string "{JPN}たたかう きぶんじゃない.\p"
	.string "{JPN}まわりを よく みてみろよ...\p"
	.string "{JPN}かざんが ばくはつして\n"
	.string "{JPN}まち ひとつが きえちまう.\n"
	.string "{JPN}ポケモンで かったり\n"
	.string "{JPN}まけたりは できるが\l"
	.string "{JPN}しぜんが ちょっと\l"
	.string "{JPN}うごけば いっしゅんで\l"
	.string "{JPN}まけちまうんだ.\p"
	.string "{JPN}...\p"
	.string "{JPN}それが げんじつ なんだ...\pでも おれは やっぱり\nトレーナーだ.\nつよい あいてを みると\nたたかいたく なっちまう.\nおれと たたかいたいなら\nまず 15この バッジが\lひつようだ.\nそのときは あいてに なるぜ.$"

CinnabarIsland_Text_Blue:
	.string "{JPN}きみは だれだい?\p"
	.string "{JPN}まあ みたところ\n"
	.string "{JPN}トレーナーの ようだが...\p"
	.string "{JPN}おれの なまえは グリーン.\p"
	.string "{JPN}いちど チャンピオンに\n"
	.string "{JPN}なったことが あるんだ...\p"
	.string "{JPN}ほんの みじかいあいだ\n"
	.string "{JPN}だけど な...\p"
	.string "{JPN}あの おせっかいな\n"
	.string "{JPN}レッドに やられちまった...\p"
	.string "{JPN}ところで なんの ようだ?\n"
	.string "{JPN}おれに ちょうせん でも\l"
	.string "{JPN}するつもりか?\p"
	.string "{JPN}...くやしいが いまは\n"
	.string "{JPN}たたかう きぶんじゃない.\p"
	.string "{JPN}まわりを よく みてみろよ...\p"
	.string "{JPN}かざんが ばくはつして\n"
	.string "{JPN}まち ひとつが きえちまう.\n"
	.string "{JPN}ポケモンで かったり\n"
	.string "{JPN}まけたりは できるが\l"
	.string "{JPN}しぜんが ちょっと\l"
	.string "{JPN}うごけば いっしゅんで\l"
	.string "{JPN}まけちまうんだ.\p"
	.string "{JPN}...\p"
	.string "{JPN}それが げんじつ なんだ...\pでも おれは やっぱり\nトレーナーだ.\nつよい あいてを みると\nたたかいたく なっちまう.\nおれと たたかいたいなら\nトキワジムに こい.\nそのときは あいてに なるぜ.$"

CinnabarIsland_EventScript_Sign::
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_GymSign:
	.string "{JPN}..おしらせがはってある！\p"
	.string "{JPN}グレンタウンのジムは\n"
	.string "{JPN}ふたごじまにうつりました\l"
	.string "{JPN}..カツラ$"
CinnabarIsland_Text_Sign:
	.string "{JPN}グレンじま\p"
	.string "{JPN}もえさかる よくぼうの まち$"

