
#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void *currentfont;
#define size 5
#define MAX 5
int color_menu,item_no,a=0,b=0,flag;
class button
{
	int x1,y1,x2,y2;
	int state;
	char str[10];

public:
	button()
	{

	}
	button(int x11,int y11,int x22,int y22,char *str1)
	{
		x1=x11;
		y1=y11;
		x2=x22;
		y2=y22;
		state=1;
		strcpy(str,str1);
	}
	void draw();

};
class stack
{

   button s[size];
   int top;

public:
   stack()
   {
	   top=-1;
   }
   int stfull();
   button pop();
   void push(int item);
   int stempty();
   void displaystack();
};
stack st;
class queue
{
button que[MAX];
int front,rear;
public:
queue()
{
	front=-1;
	rear=-1;
}
void displayqueue();
void insert_element();
void delete_element();
};
queue q;
void setFont(void *font)
{
	currentfont=font;
}
void drawstring(float x,float y,char *string)
{
	    char *c;
	glRasterPos2f(x,y);


	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
	}
}
void button::draw()
{

	glColor3f(1.0,1.0,1.0);
		drawstring(x1+10,y1+10,str);
	glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
	glEnd();

}
int stack::stfull() {
   if (st.top >= size-1)
      return 1;
   else
      return 0;
}
void stack::push(int item) {
	char str[10];
	snprintf(str, sizeof(str), "%d", item);
   button btn(100,250+st.top*50,150,300+st.top*50,str);
	st.top++;
	a++;

   st.s[st.top] = btn;

}
button stack::pop() {
   button item;
   item = st.s[st.top];
    st.top--;
    a--;
if(st.top==0)
{

    drawstring(10,10,"Overflow");
}
return (item);
}
int stack::stempty() {
   if (st.top == -1)
      return 1;
   else
      return 0;
}
void stack::displaystack() {

    if(st.top<=-1)
    {

        drawstring(10,70,"Underflow");
    }
    for(int i=700;i>=0;i--)
    {
        drawstring(285,i,"|");
    }
   int i;



      for (i = st.top; i >= 0; i--)
        {


    	  st.s[i].draw();
        }
        if(a==5)
        {

            drawstring(10,50,"Overflow");
        }

   }


void queue::insert_element()
{
  static int num=0;
  char str[10];
  	snprintf(str, sizeof(str), "%d", num++);
     button btn(300,250+rear*50,350,300+rear*50,str);
  if(front==0 && rear==MAX-1)
    drawstring(10,10," Queue OverFlow Occured");
  else if(front==-1&&rear==-1)
  {
      front=rear=0;
      que[rear]=btn;

  }
  else if(rear==MAX-1 && front!=0)
  {
    rear=0;
    que[rear]=btn;
  }
  else
  {
      rear++;

      que[rear]=btn;
  }
}
void queue::delete_element()
{
  button element;
  if(front==-1)
  {
      drawstring(300,10," Underflow");
  }
  element=que[front];
  if(front==rear)
     front=rear=-1;
  else
  {
    if(front==MAX-1)
      front=0;
    else
      front++;

  //     printf("\n The deleted element is: %s",element.str);
  }

}
void queue::displayqueue()
{
    drawstring(350,500,"QUEUE");
    int i;



 //     printf("\n The queue elements are:\n ");
      for(i=front;i<=rear;i++)

      {


que[i].draw();


      }
      if(front==-1)
      {

          drawstring(350,70,"Underflow");
      }
      else if((front==0)&&(rear==MAX-1))
      {
          drawstring(350,70,"Overflow");
      }

    }


void displaystacknqueue()
{
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glClearColor(1.0,1.0,1.0,0.0);

glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	 drawstring(150,500,"STACKS");
st.displaystack();
q.displayqueue();
glFlush();
glutSwapBuffers();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0,0,1);
    drawstring(330.0,650.0,"SDMIT UJIRE");
    glColor3f(0.7,0,1);
    drawstring(200,600,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(1,0.5,0);
    drawstring(250,500,"A MINI PROJECT ON");
    glColor3f(1,0,0);
    drawstring(180,450,"SIMULATION ON WORKING OF STACKS AND QUEUES");
    glColor3f(1,0.5,0);
    drawstring(285,430,"BY");
    glColor3f(0.5,0,0.5);

drawstring(220,360,"ANKITH K BANGERA         (4SU16CS014)");
    glColor3f(0.5,0,0.5);

    drawstring(220,400,"AVINASH HEGDE S           (4SU16CS020)");

    glColor3f(1,0.5,0);
    drawstring(135,150,"GUIDED BY: PROF. SNEHA SHETTY");
    glColor3f(0.5,0.2,0.2);
    drawstring(135,110,"GUIDED BY: PROF. RAKSHITH M.D");
    glColor3f(0.5,0.2,0.2);

    drawstring(275,50,"PRESS S AND DOUBLE CLICK ON THE SCREEN TO START AND Q TO QUIT:");
    glutSwapBuffers();
    glFlush();
}

void keyfunc (unsigned char key, int x, int y)
{
   switch(key) {

      case 'S' :
      case 's':

         // glutDisplayFunc(keys);
          // glutPostRedisplay();
            if(flag==0)
            flag=1;

         break;
      case 'n':
      //case 'N': prac();
        //break;
      case 'q':
      case 'Q':
             exit(0);
    }
}
void mydisplay(void){
   glClear(GL_COLOR_BUFFER_BIT);
   if(flag==0)
     display();
   if(flag==1)
    displaystacknqueue();

}
void operation(int id)
{
    switch(id)
    {


    case 1:if(!st.stfull())
		st.push(item_no++);
            glutPostRedisplay();
            break;

    case 2:
            st.pop();
            glutPostRedisplay();
            break;

    case 3:q.insert_element();
            glutPostRedisplay();
        break;

    case 4:q.delete_element();
            glutPostRedisplay();
        break;

    case 5:exit(0);
        glutPostRedisplay();
        break;


    }

}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,600,0,600);
	glMatrixMode(GL_MODELVIEW);

}


int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(1800,1800);
glutCreateWindow("STACK AND QUEUE");

glutInitWindowPosition(0,0);
glutDisplayFunc(mydisplay);
glutKeyboardFunc(keyfunc);
color_menu=glutCreateMenu(operation);
glutAddMenuEntry("stack Push",1);
glutAddMenuEntry("Stack pop",2);
glutAddMenuEntry("Queue insert",3);
glutAddMenuEntry("Queue delete",4);
glutAddMenuEntry("Exit",5);
glutAttachMenu(GLUT_RIGHT_BUTTON);

glEnable(GL_DEPTH_TEST);
init();
display();
glutMainLoop();
return 0;
}
