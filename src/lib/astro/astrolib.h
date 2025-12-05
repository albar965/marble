//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2014 Gerhard Holtkamp
//

#if !defined(__astrolib_h)
#define __astrolib_h

#include "attlib.h"
#include "astrolib_export.h"

/***********************************************************************
   Definitions of Astrolib Functions


   License: GNU LGPL Version 2+

   Author: Gerhard HOLTKAMP               14-JAN-2012
 ***********************************************************************/

ASTROLIB_EXPORT double ddd(int d, int m, double s);   // deg, min, sec -> decimal degrees
ASTROLIB_EXPORT void dms(double dd, int& d, int& m, double& s);   // dec deg -> deg, min, sec
ASTROLIB_EXPORT double mjd(int day, int month, int year, double hour);   // modified Julian date
ASTROLIB_EXPORT double julcent(double mjuld);                  // Julian centuries since 2000.0
ASTROLIB_EXPORT void caldat(double mjd, int& day, int& month, int& year, double& hour);
ASTROLIB_EXPORT double DefTdUt(int yr);     // default value for TDT - UT in seconds
ASTROLIB_EXPORT double lsidtim(double jd, double lambda, double ep2);    // Sidereal Time

ASTROLIB_EXPORT double eps(double t);    // obliquity of ecliptic
ASTROLIB_EXPORT Vec3 eclequ(double t, Vec3& r1);    // ecliptic -> equatorial
ASTROLIB_EXPORT Vec3 equecl(double t, Vec3& r1);    // equatorial -> ecliptic
ASTROLIB_EXPORT Mat3 pmatecl(double t1, double t2);    // ecl. precession
ASTROLIB_EXPORT Mat3 pmatequ(double t1, double t2);    // equ. precession
ASTROLIB_EXPORT Mat3 nutmat(double t, double& ep2, bool hipr = false);   // nutation (equatorial)
ASTROLIB_EXPORT Mat3 nutecl(double t, double& ep2);    // nutation matrix (ecliptic)
ASTROLIB_EXPORT Mat3 PoleMx(double xp, double yp);     // Polar motion matrix
ASTROLIB_EXPORT Vec3 aberrat(double t, Vec3& ve);     // aberration

ASTROLIB_EXPORT Vec3 GeoPos(double jd, double ep2, double lat, double lng, double ht);
ASTROLIB_EXPORT Vec3 GeoPos(double jd, double ep2, double lat, double lng, double ht,
                            double xp, double yp);
ASTROLIB_EXPORT Vec3 EquHor(double jd, double ep2, double lat, double lng, Vec3 r);
ASTROLIB_EXPORT Vec3 HorEqu(double jd, double ep2, double lat, double lng, Vec3 r);
ASTROLIB_EXPORT void AppPos(double jd, double ep2, double lat, double lng, double ht,
                            int solsys, Vec3 r, double& azim, double& elev, double& dist);
ASTROLIB_EXPORT void AppRADec(double jd, double ep2, double lat, double lng,
                              double azim, double elev, double& ra, double& dec);
ASTROLIB_EXPORT double Refract(double h, double p = 1015.0, double t = 15.0);   // refraction

ASTROLIB_EXPORT double eccanom(double man, double ecc);    // eccentric anomaly
ASTROLIB_EXPORT double hypanom(double mh, double ecc);     // hyperbolic anomaly
ASTROLIB_EXPORT void ellip(double gm, double t0, double t, double a, double ecc,
                           double m0, Vec3& r1, Vec3& v1); // elliptic state vector
ASTROLIB_EXPORT void hyperb(double gm, double t0, double t, double a, double ecc,
                            Vec3& r1, Vec3& v1); // hyperbolic state vector
ASTROLIB_EXPORT void parab(double gm, double t0, double t, double q, double ecc,
                           Vec3& r1, Vec3& v1); // elliptic state vector
ASTROLIB_EXPORT void kepler(double gm, double t0, double t, double m0, double a, double ecc,
                            double ran, double aper, double inc, Vec3& r1, Vec3& v1);
ASTROLIB_EXPORT void oscelm(double gm, double t, Vec3& r1, Vec3& v1,
                            double& t0, double& m0, double& a, double& ecc,
                            double& ran, double& aper, double& inc);

ASTROLIB_EXPORT Vec3 QuickSun(double t);     // low precision position of the Sun at time t

class ASTROLIB_EXPORT Sun200 // Calculating the Sun in epoch J2000.0 coordinates
{
public:
  Sun200();
  Vec3 position(double t);     // position of the Sun
  void state(double t, Vec3& rs, Vec3& vs);    // State vector of the Sun

private:
  double c3[9], s3[9];
  double c[9], s[9];
  double m2, m3, m4, m5, m6;
  double d, a, uu, tt;
  double cl, sl, cb, sb;
  double u, v, dl, dr, db;
  void addthe(double c1, double s1, double c2, double s2,
              double& cc, double& ss);
  void term(int i1, int i, int it, double dlc, double dls, double drc,
            double drs, double dbc, double dbs);
  void pertven();
  void pertmar();
  void pertjup();
  void pertsat();
  void pertmoo();

};

#endif // __astrolib_h sentry.
