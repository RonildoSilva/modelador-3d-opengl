#include "filemanipulation.h"

FileManipulation::FileManipulation()
{

}

vector<Model*> FileManipulation::carregarEstado(vector<Model*> listaModelos){
    std::ifstream file("../Modelador3D/state.txt");
    if (!file) {
        cout << "Erro de leitura";
    }

    string nomeModelo;
    float tx, ty, tz = 0;
    float ax, ay, az = 0;
    float sx, sy, sz = 0;

    while(!file.eof()){

        file >> nomeModelo;

        if(nomeModelo == "Torus"){
            file >> tx >> ty >> tz;
            file >> ax >> ay >> az;
            file >> sx >> sy >> sz;

            Torus * torus = new Torus();
            torus->init(tx, ty, tz, ax, ay, az, sx, sy, sz);
            listaModelos.push_back(torus);
        }
        else if(nomeModelo == "Teapot"){
            file >> tx >> ty >> tz;
            file >> ax >> ay >> az;
            file >> sx >> sy >> sz;

            Teapot * teapot = new Teapot();
            teapot->init(tx,ty,tz, ax,ay,az, sx,sy,sz);
            listaModelos.push_back(teapot);
        }

        else if(nomeModelo == "Cube"){
            file >> tx >> ty >> tz;
            file >> ax >> ay >> az;
            file >> sx >> sy >> sz;

            Cube * cube = new Cube();
            cube->init(tx,ty,tz, ax,ay,az, sx,sy,sz);
            listaModelos.push_back(cube);
        }

        else if(nomeModelo == "Arvore"){
            file >> tx >> ty >> tz;
            file >> ax >> ay >> az;
            file >> sx >> sy >> sz;

            Tree * tree = new Tree();
            tree->init(tx,ty,tz, ax,ay,az, sx,sy,sz);

            listaModelos.push_back(tree);
        }

        else if(nomeModelo == "Luz"){
            file >> tx >> ty >> tz;
            file >> ax >> ay >> az;
            file >> sx >> sy >> sz;

            Luz * luz = new Luz();
            luz->init(tx,ty,tz, ax,ay,az, sx,sy,sz);
            listaModelos.push_back(luz);
        }

        else if(nomeModelo == "Kratos" || nomeModelo == "Mario" || nomeModelo == "Boy" || nomeModelo == "Shelf"){
            string diretorio = "../Modelador3D/data/obj/";
            string extensao = ".obj";

            file >> tx >> ty >> tz;
            file >> ax >> ay >> az;
            file >> sx >> sy >> sz;

            string param = diretorio+nomeModelo+extensao;
            ObjModelLoader * objModelLoader = new ObjModelLoader(param, nomeModelo);
            objModelLoader->init(tx,ty,tz, ax,ay,az, sx,sy,sz);

            listaModelos.push_back(objModelLoader);
        }

        else if(nomeModelo == "Esqueleto" || nomeModelo == "Cachorro" || nomeModelo == "Lobo"){
            string diretorio = "../Modelador3D/data/3ds/";
            string extensao = ".3ds";

            file >> tx >> ty >> tz;
            file >> ax >> ay >> az;
            file >> sx >> sy >> sz;

            string param = diretorio+nomeModelo+extensao;

            //string 2 * char
            const char * pm = param.c_str();

            TdsModelLoader * tdsModelLoader = new TdsModelLoader(pm, nomeModelo);
            tdsModelLoader->init(tx, ty, tz, ax, ay, az, sx, sy, sz);
            listaModelos.push_back(tdsModelLoader);
        }

    }

    //listaModelos.pop_back();

    return listaModelos;
}

void FileManipulation::salvarEstado(vector<Model*> listaModelos){
    ofstream myfile ("../Modelador3D/state.txt");
    if (myfile.is_open())
    {
        for (unsigned int index = 0; index < listaModelos.size(); ++index) {

            myfile << listaModelos.at(index)->getNome() << " ";

            myfile << listaModelos.at(index)->getTX() << " ";
            myfile << listaModelos.at(index)->getTY() << " ";
            myfile << listaModelos.at(index)->getTZ() << " ";

            myfile << listaModelos.at(index)->getAX() << " ";
            myfile << listaModelos.at(index)->getAY() << " ";
            myfile << listaModelos.at(index)->getAZ() << " ";

            myfile << listaModelos.at(index)->getSX() << " ";
            myfile << listaModelos.at(index)->getSY() << " ";
            myfile << listaModelos.at(index)->getSZ() << " ";

            myfile << "\n";
        }

        myfile.close();
    }
    else cout << "Erro de leitura";
}

CameraDistante * FileManipulation::carregaCamera()
{
    std::ifstream file("../Modelador3D/camera.txt");
    string nomeModelo;
    GLfloat ex, ey, ez;
    GLfloat cx, cy, cz;
    GLfloat ux, uy, uz;

    if (!file) {
        cout << "Erro de leitura";
    }

    while(!file.eof()){

        file >> nomeModelo;
        file >> ex >> ey >> ez;
        file >> cx >> cy >> cz;
        file >> ux >> uy >> uz;

        //this->cam = new CameraDistante(ex,ey,ez, cx,cy,cz, ux,uy,uz);
    }

    return new CameraDistante(ex,ey,ez, cx,cy,cz, ux,uy,uz);
}

void FileManipulation::salvaCamera(Camera * cam)
{
    ofstream myfile ("../Modelador3D/camera.txt");

    myfile << "CameraDistante";

    if (myfile.is_open())
    {
        //ecu
        myfile << " " << cam->e.x;
        myfile << " " << cam->e.y;
        myfile << " " << cam->e.z;

        myfile << " " << cam->c.x;
        myfile << " " << cam->c.y;
        myfile << " " << cam->c.z;

        myfile << " " << cam->u.x;
        myfile << " " << cam->u.y;
        myfile << " " << cam->u.z;

        myfile.close();
    }

    else cout << "Erro de leitura";
}
