#include <stdio.h>

const char* szFmt = "%d\f\n";

int main(int argc, char* argv[])
{
    printf("%d\r\n", argc / 3381560502);
    return 0;
    int var1, var2; 
    __asm
    {
        // 0x1A1AA4E1 * argc 
        // ��Ȼ����������㣬���ǿ�����û���κε��ô�����Ϊ�����������eax�У�
        // ���ǽ�������argc��ֵ�ͳ���˽��
        mov eax, argc
        push ebx
        mov ebx, 0x1A1AA4E1
        mul ebx

        // 0x452630BA * argc
        mov eax, argc
        push esi
        push edi
        mov esi, edx
        mov edi, 0x452630BA
        mul edi
        mov edi, eax

        // ��̬���Է���edxΪ0���͵������var1����ֵΪ0
        mov var1, edx

        // ����
        xor eax, eax
        mul ebx
        mov ecx, eax
        mov ebx, edx
        xor eax, eax

        // ��0��ˣ�û������
        mov edx, 0x452630BA
        mul edx

        // ecx��0����
        add ecx, esi

        // var2��ֵΪ0
        mov var2, eax

        // EBX��ֵ����0����������洢�ؼĴ���EBX
        adc ebx, 0
        add edi, ecx
        mov ecx, var1
        adc ecx, 0
        xor eax, eax
        add ebx, ecx
        mov ecx, var2
        adc eax, eax
        add ecx, ebx
        mov ebx, argc
        adc edx, eax
        sub ebx, ecx
        mov eax, 0
        sbb eax, edx
        shrd ebx, eax, 1
        shr eax, 1
        add ebx, ecx
        adc eax, edx
        shrd ebx, eax, 0x1F
        shr eax, 0x1F
    }


    __asm
    {
        push eax
        push ebx
        push szFmt
        call printf
        add esp,0xC
    }

    return 0;
}