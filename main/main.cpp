// main.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include "src/pp.h"
#include "src/executer.h"
#include <stack>

#ifdef _DEBUG
#pragma comment(lib, "opencv_world470d.lib")
#else
#pragma comment(lib, "opencv_world470.lib")
#endif

int main(int argc, char** argv)
{
    if (not (argc == 2 or argc == 3)) {
        std::cout << "引数の個数が正しくありません";
    }

    Pietpp::Executer executer{ argv[1], argv[2]};
    //executer.color_view();

    //cv::Vec3b a{ 255, 255, 255 }, b{ 0, 0, 0 };
    //cv::Vec3i a_i{ a }, b_i{ b };
    //std::cout << b_i - a_i << std::endl;

    for (int i = 0; i < 50; i++) {
        executer.next();
        //cv::waitKey(0);
    }

    /*unsigned int a = 73;
    char16_t b = u'あ';

    std::cout << (char)a << std::endl;
    std::wcout << (wchar_t)b << std::endl;
    std::cout << (int)b << std::endl;

    std::stack<int> stack;

    stack.push(1);
    stack.push(1);

    std::cout << stack.top();
    stack.pop();
    std::cout << stack.top();*/

    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
