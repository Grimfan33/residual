// Residual - Virtual machine to run LucasArts' 3D adventure games
// Copyright (C) 2003-2004 The ScummVM-Residual Team (www.scummvm.org)
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA

#include "stdafx.h"
#include "bits.h"
#include "debug.h"

const imuseTable _grimStateMusicTable[] = {
	{0, 1000,   0, 0,    0, 127,   0, ""},
	{0, 1999,   0, 0,    0, 127,   0, ""},
	{3, 1001,   0, 0,    0, 127,   0, "1001 - Manny's Office.IMC" },
	{3, 1002,   3, 8,    0,  20,  50, "1002 - Mr. Frustration.IMC"},
	{3, 1003,   3, 8,    0,  80,  12, "1002 - Mr. Frustration.IMC"},
	{3, 1004,   3, 8,    0,  90, 110, "1002 - Mr. Frustration.IMC"},
	{3, 1005,   3, 8,    0,  60, 110, "1002 - Mr. Frustration.IMC"},
	{3, 1006,   3, 8,    0,  80,  64, "1002 - Mr. Frustration.IMC"},
	{3, 1007,   3, 8,    0,  60,  60, "1002 - Mr. Frustration.IMC"},
	{3, 1008,   0, 0,    0, 127,   0, "1008 - Domino's Office.IMC"},
	{3, 1009,   0, 0,    0, 127,   0, "1009 - Copal's Office.IMC"},
	{3, 1010,   0, 0,    0, 127,   0, "1010 - Ledge.IMC"},
	{3, 1011,   0, 0,    0, 127,   0, "1011 - Roof.IMC"},
	{3, 1020,   0, 0,    0, 127,   0, "1020 - Tube Room.IMC"},
	{3, 1021,   0, 0,    0, 127,   0, "1021 - Brennis.IMC"},
	{3, 1022,   0, 0,    0, 127,   0, "1022 - Lobby.IMC"},
	{3, 1023,   0, 0,    0, 127,   0, "1023 - Packing Room.IMC"},
	{3, 1030,   0, 0,    0, 127,   0, "1030 - Garage.IMC"},
	{3, 1031,   0, 0,    0, 127,   0, "1031 - Glottis' Shop.IMC"},
	{3, 1032,   0, 0,    0, 127,   0, "1030 - Garage.IMC"},
	{3, 1040,  21, 4,  500,  60,   0, "1040 - Festival Wet.IMC"},
	{3, 1041,  21, 4,  200, 127,   0, "1041 - Festival Dry.IMC"},
	{3, 1042,  21, 4,  200,  60,   0, "1041 - Festival Dry.IMC"},
	{3, 1043,  21, 4,  200,  46,   0, "1041 - Festival Dry.IMC"},
	{3, 1044,  21, 4,  200,  87,   0, "1040 - Festival Wet.IMC"},
	{3, 1050,   0, 0,    0, 127,   0, "1050 - Headquarters.IMC"},
	{2, 1060,   0, 0,  300,  80,   0, "1060 - Real World.IMC"},
	{2, 1070,   0, 0,    0, 127,   0, "1070 - Stump Room.IMC"},
	{2, 1071,   0, 3,    0, 127,   0, "1071 - Signpost Room.IMC"},
	{2, 1072,   0, 0,    0, 127,   0, "1072 - Navigation.IMC"},
	{2, 1073,   0, 3,    0, 127,   0, "1071 - Signpost Room.IMC"},
	{2, 1074,   0, 0,    0, 127,   0, "1074 - Bone Wagon.IMC"},
	{2, 1075,   0, 0,    0, 127,   0, "1075 - Spider's Eye.IMC"},
	{2, 1076,   0, 0,    0, 127,   0, "1076 - Spider Room.IMC"},
	{2, 1077,   0, 0,    0, 127,   0, "1077 - Tree Pump Amb.IMC"},
	{2, 1078,   0, 0,    0, 127,   0, "1078 - Tree Pump.IMC"},
	{2, 1079,   0, 3,    0, 127,   0, "1071 - Signpost Room.IMC"},
	{2, 1080,   0, 0,    0, 127,   0, "1080 - Beaver Room Lobby.IMC"},
	{2, 1081,   0, 0,    0, 127,   0, "1081 - Beaver Dam.IMC"},
	{2, 1082,   0, 0,    0, 127,   0, "1083 - Beaver Room.IMC"},
	{2, 1083,   0, 0,    0, 127,   0, "1083 - Beaver Room.IMC"},
	{2, 1084,   0, 0,    0,  80,   0, "1084 - Foggy Cactus.IMC"},
	{2, 1085,   0, 0,    0, 105,   0, "1085 - Rubamat Exterior.IMC"},
	{2, 1086,   0, 4,    0,  80,  30, "1086 - Blue Hector.IMC"},
	{2, 1100,   0, 0,    0, 127,   0, "1109 - Cafe Exterior.IMC"},
	{3, 1101,  45, 5,  400,  60,   0, "1101 - Cafe Office.IMC"},
	{3, 1102,  45, 0,  400, 127,   0, "1102 - Cafe Intercom.IMC"},
	{3, 1103,  49, 4,  400,  60, 100, "1103 - Coat Check.IMC"},
	{2, 1104,   0, 0,  300, 127,   0, "1104 - Lupe.IMC"},
	{3, 1105,  49, 4,  400, 127,  75, "1106 - Glottis Noodle.IMC"},
	{3, 1106,  49, 4,  400, 127,  75, "1106 - Glottis Noodle.IMC"},
	{3, 1190,  49, 4,  400,  80,  45, "1106 - Glottis Noodle.IMC"},
	{3, 1191,  49, 4,  400, 127, 127, "1106 - Glottis Noodle.IMC"},
	{3, 1107,  45, 5,  400, 127,   0, "1101 - Cafe Office.IMC"},
	{3, 1108,  45, 6,  400, 127,   0, "1108 - Casino Interior.IMC"},
	{2, 1109,   0, 0,  400, 127,   0, "1109 - Cafe Exterior.IMC"},
	{2, 1110,   0, 0,  400, 105,   0, "1110 - Cafe Ledge.IMC"},
	{3, 1111,   0, 0,  400,  60,   0, "1108 - Casino Interior.IMC"},
	{2, 1112,   0, 0,  400, 127,  68, "1112 - Rusty Sans Vox.IMC"},
	{2, 1120,   0, 0,    0, 127,   0, "1120 - Elevator Station.IMC"},
	{3, 1121,   0, 0,  400, 127,   0, "1122 - Blue Exterior.IMC"},
	{3, 1122,   0, 0,  400, 127,   0, "1122 - Blue Exterior.IMC"},
	{2, 1123,   0, 4,  700, 127,   0, "1123 - Blue Casket Ins.IMC"},
	{2, 1124,   0, 0,    0, 127,   0, "1124 - Blue Casket Amb.IMC"},
	{2, 1125,   0, 4,    0,  80,  75, "1125 - Smooth Hector.IMC"},
	{3, 1126,   0, 0,  400, 127,   0, "1122 - Blue Exterior.IMC"},
	{3, 1127,  66, 0,    0, 127,   0, "1127 - Limbo Dock.IMC"},
	{2, 1128,   0, 0,  400, 127,   0, "1128 - Limbo Talk.IMC"},
	{3, 1129,  66, 0,    0, 127,   0, "1129 - Limbo Poem.IMC"},
	{2, 1130,   0, 0,  400, 127,   0, "1130 - Dry Dock.IMC"},
	{2, 1131,   0, 0,  400, 127,   0, "1131 - Dry Dock Strike.IMC"},
	{2, 1132,   0, 0,    0, 127,   0, "1132 - Lighthouse Ext.IMC"},
	{2, 1133,   0, 0,    0, 127,   0, "1133 - Lola's Last.IMC"},
	{3, 1140,   0, 0,    0, 127,   0, "1140 - Police Station.IMC"},
	{2, 1141,   0, 0,    0, 105,   0, "1141 - Police Interior.IMC"},
	{2, 1142,   0, 0,    0, 105,   0, "1141 - Police Interior.IMC"},
	{2, 1143,   0, 0,    0, 105,   0, "1143 - Morgue.IMC"},
	{3, 1144,   0, 0,    0, 105,   0, "1140 - Police Station.IMC"},
	{2, 1145,   0, 0,    0, 127,   0, "1145 - Bridge Blimp.IMC"},
	{2, 1146,   0, 0,    0,  80,   0, "1146 - LOL Security Ext.IMC"},
	{2, 1147,   0, 0,    0, 127,   0, "1147 - LOL Security Int.IMC"},
	{2, 1148,   0, 0,    0, 127,   0, "1148 - Carla's Life.IMC"},
	{2, 1149,   0, 0,  400, 127,   0, "1149 - Bomb.IMC"},
	{3, 1150,  83, 0,    0, 105,   0, "1150 - Track Stairs.IMC"},
	{3, 1151,  83, 0,    0, 105,   0, "1151 - Track Stairs.IMC"},
	{3, 1152,  83, 0,    0, 105,   0, "1152 - Track Stairs.IMC"},
	{2, 1153,   0, 0,  400, 127,   0, "1153 - Track Base.IMC"},
	{2, 1154,   0, 0,    0, 127,   0, "1154 - Kitty Hall.IMC"},
	{2, 1155,   0, 0,    0, 127,   0, "1155 - Sanspoof.IMC"},
	{2, 1156,   0, 0,    0, 127,   0, "1156 - Kitty Stables.IMC"},
	{2, 1160,   0, 0,    0, 127,   0, "1160 - High Roller Hall.IMC"},
	{3, 1161,   0, 0,  400, 127,   0, "1161 - High Roller Lnge.IMC"},
	{2, 1162,   0, 0,    0, 127,   0, "1162 - Glottis Gambling.IMC"},
	{3, 1163,   0, 0,  400, 127,   0, "1163 - Max's Office.IMC"},
	{3, 1164,  94, 4,  200, 127,  80, "1125 - Hector Steps Out.IMC"},
	{3, 1165,  94, 4,  200,  20,  64, "1125 - Hector Steps Out.IMC"},
	{3, 1166,  94, 4,  200, 127,  10, "1125 - Hector Steps Out.IMC"},
	{3, 1167,   0, 0,    0, 127,   0, "1167 - Dillopede Elev.IMC"},
	{3, 1168,   0, 0,    0, 127,   0, "1168 - Dillopede Elev.IMC"},
	{3, 1169,   0, 0,    0, 127,   0, "1169 - Dillopede Elev.IMC"},
	{3, 1170,   0, 0,  400, 105,   0, "1170 - Extendo Bridge.IMC"},
	{3, 1171,   0, 0,  400, 105,   0, "1170 - Extendo Bridge.IMC"},
	{3, 1172,   0, 0,  400, 105,   0, "1170 - Extendo Bridge.IMC"},
	{2, 1173,   0, 0,  400, 127,   0, "1173 - Scrimshaw Int.IMC"},
	{2, 1174,   0, 0,  400, 127,   0, "1174 - Scrim Sleep.IMC"},
	{2, 1180,   0, 0,    0,  72,   0, "1180 - Note to Manny.IMC"},
	{2, 1181,   0, 0,    0, 127,   0, "1155 - Sanspoof.IMC"},
	{2, 1201,   0, 0,    0, 127,   0, "1201 - Lola Zapata.IMC"},
	{2, 1202,   0, 0,    0, 127,   0, "1202 - Inside the Lola.IMC"},
	{2, 1203,   0, 0,    0, 127,   0, "1203 - Engine Room.IMC"},
	{2, 1204,   0, 0,    0, 127,   0, "1204 - Porthole.IMC"},
	{2, 1205,   0, 0,    0, 127,   0, "1204 - Porthole.IMC"},
	{2, 1210,   0, 0,    0, 127,   0, "1210 - Sunken Lola.IMC"},
	{2, 1211,   0, 0,    0, 127,   0, "1211 - Pearl Crater Sub.IMC"},
	{3, 1220,   0, 0,    0, 127,   0, "1220 - Miner's Room.IMC"},
	{3, 1221,   0, 0,    0, 127,   0, "1221 - Miner's Room.IMC"},
	{2, 1222,   0, 0,    0, 127,   0, "1222 - Exterior Airlock.IMC"},
	{2, 1223,   0, 4,    0, 127,   0, "1223 - Factory Hub.IMC"},
	{2, 1224,   0, 0,    0, 127,   0, "1224 - Foreman's Office.IMC"},
	{2, 1230,   0, 0,    0, 127,   0, "1230 - Vault Door.IMC"},
	{2, 1231,   0, 0,    0, 127,   0, "1231 - Outer Vault.IMC"},
	{2, 1232,   0, 0,    0, 127,   0, "1232 - Inner Vault.IMC"},
	{2, 1233,   0, 0,    0, 127,   0, "1233 - Ashtray Room.IMC"},
	{2, 1234,   0, 0,    0, 127,   0, "1234 - Ashtray Scary.IMC"},
	{2, 1235,   0, 0,    0, 127,   0, "1235 - Ashtray Pensive.IMC"},
	{2, 1236,   0, 0,    0, 127,   0, "1236 - Domino's Room.IMC"},
	{3, 1240,   0, 4,    0, 127,   0, "1240 - Conveyor Under.IMC"},
	{3, 1241,   0, 0,    0, 127,   0, "1240 - Conveyor Under.IMC"},
	{2, 1242,   0, 0,    0, 127,   0, "1241 - Crane Intro.IMC"},
	{3, 1243,   0, 0,    0, 127,   0, "1243 - Anchor Room.IMC"},
	{2, 1244,   0, 0,    0, 127,   0, "1244 - Glottis Hanging.IMC"},
	{2, 1245,   0, 0,    0, 127,   0, "1245 - End of the World.IMC"},
	{2, 1246,   0, 0,    0, 127,   0, "1246 - End World Later.IMC"},
	{2, 1247,   0, 0,    0, 127,   0, "1241 - Crane Intro.IMC"},
	{3, 1250,   0, 0,    0, 127,   0, "1250 - Upper Beach.IMC"},
	{3, 1251,   0, 0,    0, 127,   0, "1250 - Upper Beach.IMC"},
	{3, 1252,   0, 0,    0, 127,   0, "1252 - Lower Beach Boat.IMC"},
	{2, 1253,   0, 0,    0, 127,   0, "1253 - Lamancha Sub.IMC"},
	{2, 1254,   0, 0,    0, 127,   0, "1254 - Crane Later.IMC"},
	{3, 1301,   0, 0,    0, 127,   0, "1301 - Temple Gate.IMC"},
	{3, 1302,   0, 0,    0, 127,   0, "1301 - Temple Gate.IMC"},
	{2, 1303,   0, 0,    0, 105,   0, "1303 - Truck Depot.IMC"},
	{3, 1306, 143, 0,    0, 127,   0, "1304 - Mayan Train Sta.IMC"},
	{3, 1304, 143, 0,    0, 127,   0, "1305 - Mayan Workshop.IMC"},
	{2, 1305,   0, 0,    0, 127,   0, "1306 - Mayan Train Pad.IMC"},
	{2, 1307,   0, 4,    0,  40,  64, "1307 - Mechanic's Kitch.IMC"},
	{3, 1310,   0, 0,    0, 127,   0, "1310 - Jello Bomb.IMC"},
	{3, 1311,   0, 0,    0, 127,   0, "1310 - Jello Bomb.IMC"},
	{3, 1312, 150, 4,  200,  20,  64, "1125 - Smooth Hector.IMC"},
	{3, 1313, 150, 4,  200,  50,  32, "1125 - Smooth Hector.IMC"},
	{3, 1314, 150, 4,  200, 105,  75, "1125 - Smooth Hector.IMC"},
	{3, 1315,   0, 0,    0, 127,   0, "1122 - Blue Exterior.IMC"},
	{3, 1316,   0, 0,    0, 127,   0, "1122 - Blue Exterior.IMC"},
	{3, 1317,   0, 0,    0, 127,   0, "1122 - Blue Exterior.IMC"},
	{3, 1318,   0, 0,    0, 127,   0, "1332 - Hector's Foyer.IMC"},
	{2, 1319,   0, 0,    0, 127,   0, "1319 - Florist Video.IMC"},
	{2, 1320,   0, 0,    0, 127,   0, "1320 - New LSA HQ.IMC"},
	{3, 1321,   0, 0,    0, 127,   0, "1321 - LSA Sewer.IMC"},
	{3, 1322,   0, 0,    0, 127,   0, "1321 - LSA Sewer.IMC"},
	{3, 1323,   0, 2,    0, 127,   0, "1323 - Sewer Maze.IMC"},
	{3, 1324,   0, 0,    0, 127,   0, "1324 - Albinozod.IMC"},
	{3, 1334,   0, 0,    0, 127,   0, "1334 - Albino Trap.IMC"},
	{3, 1325, 162, 0,    0, 127,   0, "1325 - Florist Shop.IMC"},
	{3, 1326, 162, 0,    0, 127,   0, "1326 - Florist Shop Int.IMC"},
	{2, 1327,   0, 0,    0, 127,   0, "1327 - Florist OK.IMC"},
	{3, 1328,   0, 2,    0, 127,   0, "1323 - Sewer Maze.IMC"},
	{2, 1329,   0, 4,    0, 127,   0, "1329 - Theater Backstag.IMC"},
	{2, 1330,   0, 0,    0, 127,   0, "1330 - Lemans Lobby.IMC"},
	{2, 1331,   0, 0,    0,  60,   0, "1330 - Lemans Lobby.IMC"},
	{2, 1333,   0, 0,    0, 127,   0, "1333 - Brennis Talk.IMC"},
	{3, 1332,   0, 0,    0, 127,   0, "1332 - Hector's Foyer.IMC"},
	{2, 1340,   0, 0,    0, 127,   0, "1342 - Neon Ledge.IMC"},
	{2, 1350,   0, 0,    0, 127,   0, "1350 - Meadow Flowers.IMC"},
	{2, 1351,   0, 0,    0, 127,   0, "1351 - Meadow.IMC"},
	{2, 1352,   0, 0,    0, 127,   0, "1352 - Car Head.IMC"},
	{2, 1353,   0, 0,    0, 127,   0, "1353 - Greenhouse Appr.IMC"},
	{2, 1355,   0, 0,    0, 127,   0, "1354 - Game Ending.IMC"},
	{2, 1354,   0, 0,    0, 127,   0, "1355 - Shootout.IMC"},
	{2, 1400,   0, 0,    0,  20, 105, "1400 - Start Credits.IMC"},
	{2, 1401,   0, 0,    0, 127,   0, "1401 - Smooth Hector.IMC"},
	{0, 1500,   0, 0,    0, 127,   0, ""},
	{0,   -1,   0, 0,    0,   0,   0, ""}
};

const imuseTable _grimSeqMusicTable[] = {
	{0, 2000,   0, 0,  300, 127,   0, ""},
	{2, 2001,   0, 0,  300, 127,   0, "2001 - Climb Rope.IMC"},
	{2, 2010,   0, 0,  300, 127,   0, "2010 - Glottis OK.IMC"},
	{2, 2020,   0, 0,  300, 127,   0, "2020 - Reap Bruno.IMC"},
	{2, 2030,   0, 0,  300, 127,   0, "2030 - Ledgepeckers.IMC"},
	{2, 2050,   0, 0,  300, 105,   0, "2050 - Glottis Heart.IMC"},
	{2, 2055,   0, 0,  300, 127,   0, "2055 - Slingshot Bone.IMC"},
	{2, 2060,   0, 0,  300, 127,   0, "2060 - Glott Tree Fall.IMC"},
	{2, 2070,   0, 0,  300, 127,   0, "2070 - Beaver Fly.IMC"},
	{2, 2071,   0, 0,  300, 127,   0, "2071 - Beaver Sink.IMC"},
	{2, 2080,   0, 0,  300, 127,   0, "2080 - Meet Velasco.IMC"},
	{2, 2140,   0, 0,  300, 127,  75, "2140 - Ooo Bonewagon.IMC"},
	{2, 2141,   0, 0,  300, 127,  75, "2141 - Ooo Meche.IMC"},
	{2, 2155,   0, 0,  300, 127,   0, "2155 - Find Detector.IMC"},
	{2, 2156,   0, 0,  300, 127,   0, "2156 - Glott Drink Wine.IMC"},
	{2, 2157,   0, 0,  300, 127,   0, "2157 - Glott No Wine.IMC"},
	{2, 2161,   0, 0,  300, 127,   0, "2161 - Raoul Appears.IMC"},
	{2, 2162,   0, 0,  300, 127,   0, "2162 - Raoul KO.IMC"},
	{2, 2163,   0, 0,  300, 127,   0, "2163 - Raoul Dissed.IMC"},
	{2, 2165,   0, 0,  300, 127,   0, "2165 - Fake Tix.IMC"},
	{2, 2180,   0, 0,  300, 127,   0, "2180 - Befriend Commies.IMC"},
	{2, 2186,   0, 0,  300, 127,   0, "2186 - Nick Punchout.IMC"},
	{2, 2200,   0, 0,  300, 127,   0, "2200 - Year 3 Iris.IMC"},
	{2, 2210,   0, 0,  700, 127,   0, "2210 - Hit Men.IMC"},
	{2, 2230,   0, 0,  300, 127,   0, "2230 - Open Vault.IMC"},
	{2, 2235,   0, 0,  300, 127,   0, "2235 - Dead Tix.IMC"},
	{2, 2240,   0, 0,  500, 127,   0, "2240 - Sprinkler.IMC"},
	{2, 2250,   0, 0,  300, 127,   0, "2250 - Crane Track.IMC"},
	{2, 2255,   0, 0,  300, 127,   0, "2255 - Crane Fall.IMC"},
	{2, 2300,   0, 0,  300, 127,   0, "2300 - Yr 4 Iris.IMC"},
	{2, 2301,   0, 0,  300, 127,   0, "2301 - Pop Bruno Casket.IMC"},
	{2, 2310,   0, 0,  300, 127,   0, "2310 - Rocket Idea.IMC"},
	{2, 2320,   0, 0,  300, 127,   0, "2320 - Jello Suspense.IMC"},
	{2, 2325,   0, 0,  300, 127,   0, "2325 - Lumbago Lemo.IMC"},
	{2, 2327,   0, 0,  300, 127,   0, "2327 - Breath Mint.IMC"},
	{2, 2330,   0, 0,  300, 127,   0, "2330 - Pigeon Fly.IMC"},
	{2, 2340,   0, 0,  300, 127,   0, "2340 - Coffee On Boys.IMC"},
	{2, 2350,   0, 0,  300, 127,   0, "2350 - Sprout Aha.IMC"},
	{2, 2360,   0, 0,  300, 127,   0, "2360 - Chowchilla Bye.IMC"},
	{2, 2370,   0, 0,  300, 127,   0, "2370 - Salvador Death.IMC"},
	{2, 2399,   0, 0,  200, 127,   0, "2399 - End Credits.IMC"},
	{0,   -1,   0, 0,    0,   0,   0, ""}
};

const imuseTable _grimDemoStateMusicTable[] = {
	{0, 0,      0, 0,    0, 127,   0, ""},
	{0, 1000,   0, 0,    0, 127,   0, ""},
	{3, 1001,   0, 0,    0, 127,   0, "MO - Manny's Office.IMC"},
	{3, 1002,   0, 0,    0, 127,   0, "MO - Manny's Office.IMC"},
	{3, 1003,   0, 0,    0, 127,   0, "MO - Manny's Office.IMC"},
	{3, 1004,   0, 0,    0, 127,   0, "DO - Domino's Office.IMC"},
	{3, 1005,   0, 0,    0, 127,   0, "CO - Copal's Office.IMC"},
	{3, 1010,   0, 0,    0, 127,   0, "LE - Ledge.IMC"},
	{3, 1011,   0, 0,    0, 127,   0, "RF - Roof.IMC"},
	{3, 1020,   0, 0,    0, 127,   0, "TU - Tube Room.IMC"},
	{3, 1021,   0, 0,    0, 127,   0, "LO - Lobby.IMC"},
	{3, 1022,   0, 0,    0, 127,   0, "PK - Packing Room.IMC"},
	{3, 1030,   0, 0,    0, 127,   0, "PK - Packing Room.IMC"},
	{3, 1031,   0, 0,    0, 127,   0, "PK - Packing Room.IMC"},
	{3, 1040,   1, 0,   80,  60,   0, "Festival Wet.IMC"},
	{3, 1041,   1, 0,    0, 127,   0, "Festival Dry.IMC"},
	{3, 1042,   1, 0,   80,  50,   0, "Festival Dry.IMC"},
	{3, 1043,   1, 0,   80,  64,   0, "Festival Dry.IMC"},
	{3, 1044,   1, 0,   80,  75,   0, "Festival Wet.IMC"},
	{3, 1050,   0, 0,    0, 127,   0, "HQ - Headquarters.IMC"},
	{3, 1060,   0, 0,    0, 127,   0, ""},
	{0, 5000,   0, 0,    0, 127,   0, ""},
	{0,   -1,   0, 0,    0,   0,   0, ""}
};

const imuseTable _grimDemoSeqMusicTable[] = {
	{0, 2000,   0, 0,    0, 127,   0, ""},
	{3, 2100,   0, 0,    0, 127,   0, "Rope Climb.IMC"},
	{0,   -1,   0, 0,    0,   0,   0, ""}
};
