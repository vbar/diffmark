<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:param name="version"/>

  <xsl:variable name="tarfile">
    <xsl:value-of select="concat('diffmark-', $version, '.tar.gz')"/>
  </xsl:variable>

  <xsl:template match="/article">
    <xsl:copy>
      <xsl:apply-templates/>
      <para>Download now:
        <ulink>
          <xsl:attribute name="url">
	    <xsl:value-of select="$tarfile"/>
	  </xsl:attribute>
        </ulink>
      </para>
    </xsl:copy>
  </xsl:template>

  <xsl:template match="title">
    <title>
        <ulink>
          <xsl:attribute name="url">
	    <xsl:value-of select="$tarfile"/>
	  </xsl:attribute>
	  diffmark
        </ulink>
    </title>
  </xsl:template>

  <xsl:template match="@*|node()">
    <xsl:copy>
      <xsl:apply-templates select="@*|node()"/>
    </xsl:copy>
  </xsl:template>

</xsl:stylesheet>
