//
//  LoadImpulseFile.cpp
//  OctagonSimulation - All
//
//  Created by Amogh Matt on 21/03/2018.
//

#include "LoadImpulseFile.h"

void LoadImpulseFile::changeImpulseAsync(int newImpulse)
{
    if (newImpulse != currentImpulse)
    {
        currentImpulse = newImpulse;
        nowChangingImpulse = true;
    }
}

void LoadImpulseFile::timerCallback()
{
    if(nowChangingImpulse)
    {
        changeImpulse(currentImpulse);
        nowChangingImpulse = false;
    }
}

void LoadImpulseFile::changeImpulse(int impulseID)
{
    jassert(1 <= impulseID && impulseID <= 169);
    printf("Impulse ID: %d\n",impulseID);
    switch (impulseID) {
        case 1:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y00.wav");
            break;
        case 2:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y00.wav");
            break;
        case 3:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y00.wav");
            break;
        case 4:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y00.wav");
            break;
        case 5:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y00.wav");
            break;
        case 6:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y00.wav");
            break;
        case 7:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y00.wav");
            break;
        case 8:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y00.wav");
            break;
        case 9:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y00.wav");
            break;
        case 10:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y00.wav");
            break;
        case 11:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y00.wav");
            break;
        case 12:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y00.wav");
            break;
        case 13:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y00.wav");
            break;
        case 14:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y01.wav");
            break;
        case 15:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y01.wav");
            break;
        case 16:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y01.wav");
            break;
        case 17:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y01.wav");
            break;
        case 18:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y01.wav");
            break;
        case 19:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y01.wav");
            break;
        case 20:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y01.wav");
            break;
        case 21:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y01.wav");
            break;
        case 22:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y01.wav");
            break;
        case 23:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y01.wav");
            break;
        case 24:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y01.wav");
            break;
        case 25:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y01.wav");
            break;
        case 26:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y01.wav");
            break;
        case 27:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y02.wav");
            break;
        case 28:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y02.wav");
            break;
        case 29:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y02.wav");
            break;
        case 30:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y02.wav");
            break;
        case 31:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y02.wav");
            break;
        case 32:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y02.wav");
            break;
        case 33:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y02.wav");
            break;
        case 34:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y02.wav");
            break;
        case 35:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y02.wav");
            break;
        case 36:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y02.wav");
            break;
        case 37:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y02.wav");
            break;
        case 38:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y02.wav");
            break;
        case 39:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y02.wav");
            break;
        case 40:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y03.wav");
            break;
        case 41:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y03.wav");
            break;
        case 42:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y03.wav");
            break;
        case 43:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y03.wav");
            break;
        case 44:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y03.wav");
            break;
        case 45:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y03.wav");
            break;
        case 46:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y03.wav");
            break;
        case 47:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y03.wav");
            break;
        case 48:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y03.wav");
            break;
        case 49:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y03.wav");
            break;
        case 50:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y03.wav");
            break;
        case 51:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y03.wav");
            break;
        case 52:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y03.wav");
            break;
        case 53:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y04.wav");
            break;
        case 54:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y04.wav");
            break;
        case 55:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y04.wav");
            break;
        case 56:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y04.wav");
            break;
        case 57:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y04.wav");
            break;
        case 58:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y04.wav");
            break;
        case 59:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y04.wav");
            break;
        case 60:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y04.wav");
            break;
        case 61:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y04.wav");
            break;
        case 62:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y04.wav");
            break;
        case 63:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y04.wav");
            break;
        case 64:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y04.wav");
            break;
        case 65:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y04.wav");
            break;
        case 66:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y05.wav");
            break;
        case 67:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y05.wav");
            break;
        case 68:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y05.wav");
            break;
        case 69:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y05.wav");
            break;
        case 70:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y05.wav");
            break;
        case 71:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y05.wav");
            break;
        case 72:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y05.wav");
            break;
        case 73:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y05.wav");
            break;
        case 74:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y05.wav");
            break;
        case 75:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y05.wav");
            break;
        case 76:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y05.wav");
            break;
        case 77:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y05.wav");
            break;
        case 78:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y05.wav");
            break;
        case 79:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y06.wav");
            break;
        case 80:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y06.wav");
            break;
        case 81:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y06.wav");
            break;
        case 82:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y06.wav");
            break;
        case 83:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y06.wav");
            break;
        case 84:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y06.wav");
            break;
        case 85:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y06.wav");
            break;
        case 86:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y06.wav");
            break;
        case 87:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y06.wav");
            break;
        case 88:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y06.wav");
            break;
        case 89:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y06.wav");
            break;
        case 90:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y06.wav");
            break;
        case 91:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y06.wav");
            break;
        case 92:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y07.wav");
            break;
        case 93:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y07.wav");
            break;
        case 94:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y07.wav");
            break;
        case 95:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y07.wav");
            break;
        case 96:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y07.wav");
            break;
        case 97:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y07.wav");
            break;
        case 98:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y07.wav");
            break;
        case 99:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y07.wav");
            break;
        case 100:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y07.wav");
            break;
        case 101:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y07.wav");
            break;
        case 102:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y07.wav");
            break;
        case 103:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y07.wav");
            break;
        case 104:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y07.wav");
            break;
        case 105:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y08.wav");
            break;
        case 106:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y08.wav");
            break;
        case 107:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y08.wav");
            break;
        case 108:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y08.wav");
            break;
        case 109:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y08.wav");
            break;
        case 110:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y08.wav");
            break;
        case 111:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y08.wav");
            break;
        case 112:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y08.wav");
            break;
        case 113:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y08.wav");
            break;
        case 114:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y08.wav");
            break;
        case 115:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y08.wav");
            break;
        case 116:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y08.wav");
            break;
        case 117:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y08.wav");
            break;
        case 118:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y09.wav");
            break;
        case 119:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y09.wav");
            break;
        case 120:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y09.wav");
            break;
        case 121:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y09.wav");
            break;
        case 122:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y09.wav");
            break;
        case 123:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y09.wav");
            break;
        case 124:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y09.wav");
            break;
        case 125:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y09.wav");
            break;
        case 126:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y09.wav");
            break;
        case 127:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y09.wav");
            break;
        case 128:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y09.wav");
            break;
        case 129:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y09.wav");
            break;
        case 130:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y09.wav");
            break;
        case 131:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y10.wav");
            break;
        case 132:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y10.wav");
            break;
        case 133:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y10.wav");
            break;
        case 134:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y10.wav");
            break;
        case 135:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y10.wav");
            break;
        case 136:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y10.wav");
            break;
        case 137:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y10.wav");
            break;
        case 138:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y10.wav");
            break;
        case 139:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y10.wav");
            break;
        case 140:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y10.wav");
            break;
        case 141:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y10.wav");
            break;
        case 142:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y10.wav");
            break;
        case 143:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y10.wav");
            break;
        case 144:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y11.wav");
            break;
        case 145:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y11.wav");
            break;
        case 146:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y11.wav");
            break;
        case 147:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y11.wav");
            break;
        case 148:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y11.wav");
            break;
        case 149:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y11.wav");
            break;
        case 150:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y11.wav");
            break;
        case 151:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y11.wav");
            break;
        case 152:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y11.wav");
            break;
        case 153:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y11.wav");
            break;
        case 154:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y11.wav");
            break;
        case 155:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y11.wav");
            break;
        case 156:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y11.wav");
            break;
        case 157:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x00y12.wav");
            break;
        case 158:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x01y12.wav");
            break;
        case 159:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x02y12.wav");
            break;
        case 160:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x03y12.wav");
            break;
        case 161:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x04y12.wav");
            break;
        case 162:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x05y12.wav");
            break;
        case 163:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x06y12.wav");
            break;
        case 164:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x07y12.wav");
            break;
        case 165:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x08y12.wav");
            break;
        case 166:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x09y12.wav");
            break;
        case 167:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x10y12.wav");
            break;
        case 168:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x11y12.wav");
            break;
        case 169:
            impulseFile = *new File("~/Library/Audio/Plug-Ins/Impulses/x12y12.wav");
            break;
        default: jassertfalse;
            break;
    };
}
