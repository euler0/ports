# $FreeBSD: head/devel/rbenv/Makefile 327726 2013-09-20 17:17:44Z bapt $

PORTNAME=	rbenv
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	GH

MAINTAINER=	fmb@onibox.net
COMMENT=	Manage multiple versions of ruby

LICENSE=	RBENV
LICENSE_NAME=	Sam Stephenson
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	sstephenson
GH_PROJECT=	rbenv
GH_COMMIT=	9375e99
GH_TAGNAME=	v${PORTVERSION}

NO_BUILD=	yes

REINPLACE_ARGS=	-i ''

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|\$$root/completions|${DATADIR}/completions|g" ${WRKSRC}/libexec/rbenv-init

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ruby-local-exec ${PREFIX}/bin
	( ${INSTALL_SCRIPT} ${WRKSRC}/libexec/* ${PREFIX}/libexec/ )
	@${LN} -sf ${PREFIX}/libexec/rbenv ${PREFIX}/bin/rbenv
	@${MKDIR} ${DATADIR}/completions
	( cd ${WRKSRC}/completions && ${COPYTREE_BIN} \* ${DATADIR}/completions )

.include <bsd.port.mk>
