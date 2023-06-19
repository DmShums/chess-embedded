// // #include <iostream>

// struct pos{
//     int x;
//     int y;
// };

// class positions{
// public:
//     int size;
//     pos* positionsss;

//     ~positions(){
//         free(positionsss);
//     }
// };


// int get_moves_size(){
//     return 5;
// }

// void get_possible_moves(positions& poses){
//     int our_size =5;
//     poses.positions = static_cast<pos*> (malloc(sizeof(pos) * our_size));
//     poses.size = our_size;
// }

// int main(){
//     std::cout<<sizeof(pos)<<std::endl;

//     // int* p -- define pointer; variable p IS POINTER
//     // &a -- take addres of a
//     // int* p = &a
//     // int b = *p -- розіменувати п - take whats in address p

//     int a = 5;
//     int* p = &a;
//     std::cout<<"A: "<<a<<std::endl;
//     std::cout<<"P: "<<p<<std::endl;
//     std::cout<<"A: "<<*p<<std::endl;


//     positions poses{};
//     get_possible_moves(poses);

//     auto positionssss = static_cast<pos*> (malloc(sizeof(pos) * 5));

// //    ...
// //    ...


//     free(positionssss);

// //    int size = 0;
// //    auto arr = get_possible_moves(&size);
// //    std::cout<<arr[0].x<<" "<<arr[0].y<<std::endl;

//     std::cout<<"I want to die!"<<std::endl;
// }