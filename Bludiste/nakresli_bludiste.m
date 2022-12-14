nakresliBludiste("LABYRINT_bludiste.dat");
nakresliCestu("LABYRINT_cesta.dat");

function nakresliBludiste(soubor_bludiste)
  bludiste_soubor=fopen(soubor_bludiste);
  nazev=fscanf(bludiste_soubor,"%s",1);
  n=fscanf(bludiste_soubor,"%i",1);
  m=fscanf(bludiste_soubor,"%i",1);
  i_f=fscanf(bludiste_soubor,"%i",1);
  j_f=fscanf(bludiste_soubor,"%i",1);
  
  wall=zeros(n,m);
  for j=1:m
    for i=1:n
      wall(i,j) = fscanf(bludiste_soubor,"%i",1);
    end
  end
  
  hold on;
  axis([-0.5,n-0.5,-0.5,m-0.5],"equal");
  set(gca,'xtick',[0:n]);
  set(gca,'ytick',[0:m]);
  grid on;
  plot([-0.5 n-0.5],[-0.5 -0.5],'k','LineWidth',3);
  plot([n-0.5 n-0.5],[-0.5 m-0.5],'k','LineWidth',3);
  plot([n-0.5 -0.5],[m-0.5 m-0.5],'k','LineWidth',3);
  plot([-0.5 -0.5],[m-0.5 -0.5],'k','LineWidth',3);
  title(nazev);
  plot(i_f,j_f,'rx');
  for i=1:n
    for j=1:m
      if (wall(i,j))
          plot(i-1,j-1,'ks');
      end
    end
  end
end

function nakresliCestu(soubor_cesta)
  cesta=load(soubor_cesta);
  cesta_r=cesta+0.2*(rand(size(cesta,1),2) - 0.5);
  hold on;
  xlim([-0.5,19.5]);
  ylim([-0.5,9.5]);
  plot(cesta_r(:,1),cesta_r(:,2));
  plot(cesta(1,1),cesta(1,2),'gx');
end
