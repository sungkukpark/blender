/* SPDX-License-Identifier: GPL-2.0-or-later
 * Copyright 2021 Blender Foundation.
 */

/** \file
 * \ingroup eevee
 *
 * List of defines that are shared with the GPUShaderCreateInfos. We do this to avoid
 * dragging larger headers into the createInfo pipeline which would cause problems.
 */

#pragma once

/* Hierarchical Z down-sampling. */
#define HIZ_MIP_COUNT 8
/* NOTE: The shader is written to update 5 mipmaps using LDS. */
#define HIZ_GROUP_SIZE 32

/* Avoid too much overhead caused by resizing the light buffers too many time. */
#define LIGHT_CHUNK 256

#define CULLING_SELECT_GROUP_SIZE 256
#define CULLING_SORT_GROUP_SIZE 256
#define CULLING_ZBIN_GROUP_SIZE 1024
#define CULLING_TILE_GROUP_SIZE 1024

/**
 * IMPORTANT: Some data packing are tweaked for these values.
 * Be sure to update them accordingly.
 * SHADOW_TILEMAP_RES max is 32 because of the shared bitmaps used for LOD tagging.
 * It is also limited by the maximum thread group size (1024).
 */
#define SHADOW_TILEMAP_RES 16
#define SHADOW_TILEMAP_LOD 4 /* LOG2(SHADOW_TILEMAP_RES) */
#define SHADOW_TILEMAP_PER_ROW 64
#define SHADOW_PAGE_COPY_GROUP_SIZE 32
#define SHADOW_DEPTH_SCAN_GROUP_SIZE 32
#define SHADOW_AABB_TAG_GROUP_SIZE 64
#define SHADOW_MAX_TILEMAP 4096
#define SHADOW_MAX_PAGE 4096
#define SHADOW_PAGE_PER_ROW 64

/* Ray-tracing. */
#define RAYTRACE_GROUP_SIZE 16
#define RAYTRACE_MAX_TILES (16384 / RAYTRACE_GROUP_SIZE) * (16384 / RAYTRACE_GROUP_SIZE)

/* Minimum visibility size. */
#define LIGHTPROBE_FILTER_VIS_GROUP_SIZE 16

/* Film. */
#define FILM_GROUP_SIZE 16

/* Motion Blur. */
#define MOTION_BLUR_GROUP_SIZE 32
#define MOTION_BLUR_DILATE_GROUP_SIZE 512

/* Depth Of Field. */
#define DOF_TILES_SIZE 8
#define DOF_TILES_FLATTEN_GROUP_SIZE DOF_TILES_SIZE
#define DOF_TILES_DILATE_GROUP_SIZE 8
#define DOF_BOKEH_LUT_SIZE 32
#define DOF_MAX_SLIGHT_FOCUS_RADIUS 5
#define DOF_SLIGHT_FOCUS_SAMPLE_MAX 16
#define DOF_MIP_COUNT 4
#define DOF_REDUCE_GROUP_SIZE (1 << (DOF_MIP_COUNT - 1))
#define DOF_DEFAULT_GROUP_SIZE 32
#define DOF_STABILIZE_GROUP_SIZE 16
#define DOF_FILTER_GROUP_SIZE 8
#define DOF_GATHER_GROUP_SIZE DOF_TILES_SIZE
#define DOF_RESOLVE_GROUP_SIZE (DOF_TILES_SIZE * 2)

/* Resource bindings. */

/* Texture. */
#define RBUFS_UTILITY_TEX_SLOT 14

/* Images. */
#define RBUFS_NORMAL_SLOT 0
#define RBUFS_LIGHT_SLOT 1
#define RBUFS_DIFF_COLOR_SLOT 2
#define RBUFS_SPEC_COLOR_SLOT 3
#define RBUFS_EMISSION_SLOT 4
#define RBUFS_AOV_COLOR_SLOT 5
#define RBUFS_AOV_VALUE_SLOT 6

/* Uniform Bufs. */
/* Only during prepass. */
#define VELOCITY_CAMERA_PREV_BUF 3
#define VELOCITY_CAMERA_CURR_BUF 4
#define VELOCITY_CAMERA_NEXT_BUF 5

/* Storage Bufs. */
#define LIGHT_CULL_BUF_SLOT 0
#define LIGHT_BUF_SLOT 1
#define LIGHT_ZBIN_BUF_SLOT 2
#define LIGHT_TILE_BUF_SLOT 3
#define RBUFS_AOV_BUF_SLOT 5
#define SAMPLING_BUF_SLOT 6
/* Only during prepass. */
#define VELOCITY_OBJ_PREV_BUF_SLOT 0
#define VELOCITY_OBJ_NEXT_BUF_SLOT 1
#define VELOCITY_GEO_PREV_BUF_SLOT 2
#define VELOCITY_GEO_NEXT_BUF_SLOT 3
#define VELOCITY_INDIRECTION_BUF_SLOT 4
