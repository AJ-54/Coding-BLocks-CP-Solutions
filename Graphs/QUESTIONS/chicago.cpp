#include <stdio.h>
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };
#define MAXN 1024
char g[MAXN][MAXN];
int n, m;

short q[MAXN*MAXN*2];

void bfs( short y, short x)
{
  int head = 0, tail = 0, d;
  g[y][x] = '*';
  q[tail++] = y, q[tail++] = x;
  while( head != tail )
  {
    y = q[head++], x = q[head++];
    for( d = 0; d < 4; ++d)
    {
      int yy = y + dy[d], xx = x + dx[d];
      if( yy >= 0 && yy < n && xx >= 0 && xx < m && g[yy][xx] == '.' )
      {
        g[yy][xx] = '*';
        q[tail++] = yy, q[tail++] = xx;
      }
    }
  }
}

int main( void )
{
  int i, j, count = 0;
  scanf( "%d %d", &n, &m);
  for( i = 0; i < n; ++i) scanf( "%s", g[i]);
  for( i = 0; i < n; ++i)
    for( j = 0; j < m; ++j)
      if( g[i][j] == '.' ) bfs( (short) i, (short) j), count++;
  printf( "%d\n", count);
  return 0;
}