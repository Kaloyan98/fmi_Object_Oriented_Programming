Подготовка за контролно:
UNIX времево клеймо (timestamp), още наричано "epoch time", е цяло число, указващо брой секунди изминали след 1 януари 1970 г. UTC. Такова клеймо позволява всеки момент във времето след 01.01.1970 г. да се съхранява като едно-единствено цяло число. Ако едно клеймо A е по-малко от друго клеймо B, можем да заключим, че A е момент от времето, който е преди B.

Да се реализира клас Timestamp, представящ UNIX времево клеймо. Класът трябва да спазва принципа за енкапсулация и да няма външен достъп до член-променливите на класа. В класа трябва да се включат:

променлива от тип unsigned long, която пази клеймото;

конструктор по подразбиране, който задава на клеймото стойност нула (съответстващ на дата 01.01.1970 г.)

конструктор, приемащ един параметър — стойност за клеймото, с която да се инициализира класа;

функции GetValue и SetValue, които позволяват съответно да се достъпва и променя клеймото, съхранено в класа;

За класа да се предефинират следните оператори:

operator<< за изход в поток;

operator>> за вход от поток.

operator+= за добавяне на зададен брой секунди към клеймото. Операторът получава цяло число (брой секунди) и ги добавя към клеймото в класа.

operator+ за пресмятане на ново клеймо, което се получава с добавяне на даден брой секунди към дадено клеймо. Операторът получава брой секунди d, прибавя ги към клеймото на обекта, за който е извикан и връща нов обект, съдържащ новото клеймо.

Да се дефинира нов клас TimestampWithDescription, производен на класа Timestamp. Този клас трябва да надгради Timestamp като добави възможност да се задава описание на клеймото. За целта в този клас трябва да може да се съхранява символен низ с произволна дължина, който ще съдържа описанието. Класът трябва да има:

всички функции от голямата четворка;

функции GetDescription и SetDescription, които позволяват съответно да се достъпва и променя описанието;

operator<< за изход в поток;

operator>> за вход от поток.
